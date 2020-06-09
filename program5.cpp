/* prog5Boggle.cpp
      

    Running this program looks like:
        Name: Veronica Kalicki
        Program: #5, Boggle
        TA:  Moumita Samanta, Tues 9am
        Nov 19, 2017

        Welcome to the game of Boggle, where you play against the clock
        to see how many words you can find using adjacent letters on the
        board.  Each letter can be used only once for a given word.


        The dictionary total number of words is: 263533
        Number of words of the right length is:  259709

        Some random characters are: a c r l n e a p p u

        Do word lookups for 10 seconds.

        Enter a word: fish
        fish is in the dictionary.
        There are 3 seconds left.

        Enter a word: cat
        cat is in the dictionary.
        There are 3 seconds left.

        Enter a word: dog
        dog is in the dictionary.
        There are 1 seconds left.

        Enter a word: entropy
        entropy is in the dictionary.
        There are -3 seconds left.
        I let you finish your last move. Time is up!

*/
#include <iostream>   // For Input and Output
#include <fstream>    // For file input and output
#include <cassert>    // For the assert statement
#include <cctype>     // Allows using the tolower() function
#include <ctime>      // Timer functions
#include <cstring>    // For strlen

using namespace std;

// Global constants
const char DictionaryFileName[] = "dictionary.txt";
const int MaxNumberOfWords = 263533; // Number of dictionary words
const int MinWordLength = 3;         // Minimum dictionary word size to be stored
const int MaxWordLength = 16;	     // Max word size.  Add 1 for null
const int MaxUserInputLength = 81;   // Max user input length
const int NumberOfLetters = 26;      // Letters in the alphabet
const int TotalSecondsToPlay = 60;   // Total number of seconds to play per board


//--------------------------------------------------------------------------------
// Display name and program information
void displayIdentifyingInformation()
{
    printf("\n");
    printf("Author: Veronica Kalicki      \n");
    printf("Program: #5, Boggle        \n");
    printf("TA:  Moumita Samanta, Tues 9am-9:50am  \n");
    printf("Nov 19, 2017                \n");
    printf("\n");
}//end displayIdentifyingInformation()


//--------------------------------------------------------------------------------
// Display instructions
void displayInstructions()
{
    printf("Welcome to the game of Boggle, where you play against the clock   \n");
    printf("to see how many words you can find using adjacent letters on the  \n");
    printf("board.  Each letter can be used only once for a given word.       \n");
    printf("  \n");
    printf("When prompted to provide input you may also:                      \n");
    printf("     Enter 'r' to reset the board to user-defined values.         \n");
    printf("     Enter 's' to solve the board and display all possible words. \n");
    printf("     Enter 't' to toggle the timer on/off.                        \n");
    printf("     Enter 'x' to exit the program.                               \n");
    printf("  \n");
}//end displayInstructions()


//---------------------------------------------------------------------------
// Read in dictionary
//    First dynamically allocate space for the dictionary.  Then read in words
// from file.  Note that the '&' is needed so that the new array address is
// passed back as a reference parameter.
void readInDictionary(
        char ** &dictionary,                      // dictionary words
        long int &numberOfWords)                  // number of words stored
{
    // Allocate space for large array of C-style strings
    dictionary = new char*[ MaxNumberOfWords];

    // For each array entry, allocate space for the word (C-string) to be stored there
    for (int i=0; i < MaxNumberOfWords; i++) {
        dictionary[i] = new char[ MaxWordLength+1];
        // just to be safe, initialize C-strings to all null characters
        for (int j=0; j < MaxWordLength; j++) {
            dictionary[i][j] = '\0';
        }//end for (int j=0...
    }//end for (int i...

    // Now read in the words from the file
    ifstream inStream;                 // declare an input stream for my use
    numberOfWords = 0;                   // Row for the current word
    inStream.open( DictionaryFileName);
    assert( ! inStream.fail() );       // make sure file open was OK

    // Keep repeating while input from the file yields a word
    char theWord[ 81];    // declare input space to be clearly larger than largest word
    while( inStream >> theWord) {
        int wordLength = (int)strlen( theWord);
        if( wordLength >= MinWordLength && wordLength <= MaxWordLength) {
            strcpy( dictionary[ numberOfWords], theWord);
            // increment number of words
            numberOfWords++;
        }
    }//end while( inStream...

    cout << "The dictionary total number of words is: " << MaxNumberOfWords << endl;
    cout << "Number of words of the right length is:  " << numberOfWords << endl;

    // close the file
    inStream.close();
}//end readInDictionary()


//--------------------------------------------------------------------------------------
// Use binary search to look up the search word in the dictionary array, returning index
// if found, -1 otherwise
int binarySearch( const char searchWord[ MaxWordLength+1], // word to be looked up
                  char **dictionary)               // the dictionary of words
{
    int low, mid, high;     // array indices for binary search
    int searchResult = -1;  // Stores index of word if search succeeded, else -1

    // Binary search for word
    low = 0;
    high = MaxNumberOfWords - 1;
    while ( low <= high)  {
        mid = (low + high) / 2;
        // searchResult negative value means word is to the left, positive value means
        // word is to the right, value of 0 means word was found
        searchResult = strcmp( searchWord, dictionary[ mid]);
        if ( searchResult == 0)  {
            // Word IS in dictionary, so return the index where the word was found
            return mid;
        }
        else if (searchResult < 0)  {
            high = mid - 1; // word should be located prior to mid location
        }
        else  {
            low = mid + 1; // word should be located after mid location
        }
    }

    // Word was not found
    return -1;
}//end binarySearch()


//---------------------------------------------------------------------------
// Get random character
//    Find random character using a table of letter frequency counts.
// Iterate through the array and find the first position where the random number is
// less than the value stored.  The resulting index position corresponds to the
// letter to be generated (0='a', 1='b', etc.)
char getRandomCharacter()
{
    // The following table of values came from the frequency distribution of letters in the dictionary
    float letterPercentTotals[ NumberOfLetters] = {
            0.07680,  //  a
            0.09485,  //  b
            0.13527,  //  c
            0.16824,  //  d
            0.28129,  //  e
            0.29299,  //  f
            0.32033,  //  g
            0.34499,  //  h
            0.43625,  //  i
            0.43783,  //  j
            0.44627,  //  k
            0.49865,  //  l
            0.52743,  //  m
            0.59567,  //  n
            0.66222,  //  o
            0.69246,  //  p
            0.69246,  //  q
            0.76380,  //  r
            0.86042,  //  s
            0.92666,  //  t
            0.95963,  //  u
            0.96892,  //  v
            0.97616,  //  w
            0.97892,  //  x
            0.99510,  //  y
            1.00000}; //  z

    // generate a random number between 0..1
    // Multiply by 1.0 otherwise integer division truncates remainders
    float randomNumber = 1.0 * rand() / RAND_MAX;

    // Find the first position where our random number is less than the
    // value stored.  The index corresponds to the letter to be returned,
    // where 'a' is 0, 'b' is 1, and so on.
    for( int i=0; i<NumberOfLetters; i++) {
        if( randomNumber < letterPercentTotals[ i]) {
            // we found the spot.  Return the corresponding letter
            return (char) 'a' + i;
        }
    }

    // Sanity check
    cout << "No alphabetic character generated.  This should not have happened. Exiting program.\n";
    exit( -1);
    return ' ';   // should never get this
}//end getRandomCharacter

//---------------------------------------------------------------------------
//creates board and assigns input to every spot
void createBoard(char userInput[]){
    for(int i = 0; i <36; i++){
        userInput[i] = ' ';
    }
    for(int i = 7; i <11; i++){
        userInput[i] = getRandomCharacter();
    }
    for(int i = 13; i <17; i++){
        userInput[i] = getRandomCharacter();
    }
    for(int i = 19; i <23; i++){
        userInput[i] = getRandomCharacter();
    }
    for(int i = 25; i <29; i++){
        userInput[i] = getRandomCharacter();
    }
}
//---------------------------------------------------------------------------
//this displays the board when the function is called
void displayBoard(char boardDisplay[]){
    for(int i = 0; i < 36; i++){
        if( i % 6 == 0 ){
            cout << endl;
        }
        cout << boardDisplay[i] << " ";
    }
    cout << endl << endl;;
}
//---------------------------------------------------------------------------
//does lowercase for any char array
char lowerCase( char characterArray[]){
    for(int i = 0; i < MaxUserInputLength; i++){
        characterArray[i] = tolower(characterArray[i]);
    }
}

//---------------------------------------------------------------------------
//resets the board when promted to and puts new characters into the board
char resetBoard(char boardArray[]){
    char letters[MaxUserInputLength];
    int j = 0;
    cout << "Please enter 16 characters: ";
    cin >> letters;
    lowerCase(letters);
    for (int i = 0; i < 36; i++){
        if (boardArray[i] != ' '){
            boardArray[i] = letters[j];
            j++;
        }
    }
}
//---------------------------------------------------------------------------
//this is the recursion that attempts to find the rest of the word in the board
bool findSecondLetter(char theBoard[], char word[], int currentIndex, int currentLocation){
    int checkAround[] = {-1,-7,-6,-5,1,7,6,5};
    bool truthStatement = false;
    char theLetterSearch = word[currentIndex];
    for( int i = 0; i < 8; i++){

        int adjacentIndex = currentLocation + checkAround[i];
        char adjacentCharacter= theBoard[adjacentIndex];
        if( adjacentCharacter == theLetterSearch){
            char stored = theLetterSearch;
            theBoard[adjacentIndex] = ' ';
            truthStatement = findSecondLetter(theBoard,word,currentIndex+1, adjacentIndex);
            theBoard[adjacentIndex] = stored;
        }
        if(theLetterSearch =='\0'){
            truthStatement = true;
            break;
        }
    }
    return truthStatement;
}
//---------------------------------------------------------------------------
//this checks the board to see if the first index matches with any letters on the board
bool checkBoard(char board[], char word[]){
    int wordIndex = 0;
    bool truth = false;
    for(int i = 0; i < 36; i++){
        if(board[i] == word[wordIndex]){
            char foundLetter = board[i];
            board[i] = ' ';
            truth = findSecondLetter(board, word, wordIndex + 1, i);
            board[i] = foundLetter;
            if (truth == true){
                break;
            }
        }
    }
    return truth;
}
//---------------------------------------------------------------------------
//solves the board for all lengths and sizes
void solveBoard(char theBoard[], char **dictionary, int totalUsableWords){
    int minimum, maximum;
    minimum = maximum = 0;
    cout << "What is the Minimum size of the words: ";
    cin >> minimum;
    cout << "What is the Maximum size of the words: ";
    cin >> maximum;
    for(int i = 0; i < totalUsableWords; i++){
        if(checkBoard(theBoard, dictionary[i])){
            if (strlen(dictionary[i]) >= minimum && strlen(dictionary[i]) <= maximum){
                cout << dictionary[i] << ' ';
            }
        }
    }
    cout << endl;

}
//---------------------------------------------------------------------------
//function that adds the points according to size of word


//---------------------------------------------------------------------------
int main(){
    // declare variables
    char **dictionary;                // 2d array of dictionary words, dynamically allocated
    long int numberOfWords;           // how many words actually found in dictionary
    char userInput[ MaxUserInputLength];
    char theBoard[36];  //where the board is stored
    bool timerOnOFF = true; //toggles the timer on and off
    bool wordOnBoard = false; //default condition to see if the word is on board
    int score, addToScore; //ints used for scoring
    int turn = 1; //a int to keep track of turn
    score = addToScore = 0; //scores start at zero

    // srand is used to generate a new board each time the game is run
    srand(time(NULL));

    // Declare a variable to hold a time, and get the current time
    time_t startTime = time( NULL);

    displayIdentifyingInformation();
    displayInstructions();
    createBoard(theBoard);

    // read in dictionary.  numberOfWords returns the actual number of words found
    readInDictionary( dictionary, numberOfWords);
    bool chosenWords[numberOfWords];


    cout << endl << endl;

    // Loop to while there is still time left
    cout << "Do word lookups for 60 seconds." << endl;
    int elapsedSeconds = 0;
    while( elapsedSeconds < TotalSecondsToPlay) {

        //displays the board at the end of each loop
        displayBoard(theBoard);

        // Prompt for and get user input
        cout << "Score: " <<score  << endl;
        //displays turn
        cout <<  turn;
        cout << ": Enter a word: ";
        //asks for user input
        cin >> userInput;

        //takes user input and makes sure that all words are lowercase
        lowerCase(userInput);

        //if the character is an 't' it stops the timer until toggled back on
        if(userInput[0] == 't' && strlen(userInput) == 1){
            if(timerOnOFF == false){
                timerOnOFF = true;
                continue;
            } else if (timerOnOFF == true){
                timerOnOFF = false;
                continue;
            }
        }

        //if the character is an 'r' then it prompts user to reset the board
        if(userInput[0] == 'r' && strlen(userInput) == 1){
            resetBoard(theBoard);
            displayBoard(theBoard);
            continue;
        }

        //solves the board and ends the game
        if(userInput[0] == 's' && strlen(userInput) == 1){
            solveBoard(theBoard, dictionary, numberOfWords);
            turn = 1;
            break;
        }
        //if user inputs x then it will end the program
        if(userInput[0] == 'x' && strlen(userInput) == 1){
            break;
        }


        //checks to see if userInput is on the baord
        wordOnBoard = checkBoard(theBoard, userInput);
        int indexLocation = binarySearch(userInput,dictionary);

        //if userInput is on the board and in the dictionary it adds points
        if (wordOnBoard == true && binarySearch( userInput, dictionary) != -1){
            //if the word has already been found it will restart the loop after displaying error message
            if (chosenWords[indexLocation]){
                cout <<  "Word Already Used" << endl;
                continue;
            } else {
                //if the word wasnt used then it will put it in the bool array and add points to score
                chosenWords[indexLocation] = true;
            }
            //adds the points according to the length of the word
            if(strlen(userInput) < 3){
                addToScore = 0;
            } else if(strlen(userInput) == 3){
                addToScore = 1;
            } else if(strlen(userInput) == 4){
                addToScore = 2;
            } else if(strlen(userInput) == 5){
                addToScore = 4;
            } else if(strlen(userInput) >=6){
                addToScore = strlen(userInput);
            }
            score += addToScore;
        }
        //checks to see if the word is on the baord
        if (wordOnBoard == false){
            cout << "The word not on Board!" << endl;
            cout << "Score: " << score << endl;
            continue;
        } // checks to see if the user inputed word is in the dictionary
        else  if( binarySearch( userInput, dictionary) == -1) {
            cout << userInput << " is NOT in the dictionary." << endl;
            continue;
        }

        // Calculate how many seconds have elapsed since we started the timer.
        if(timerOnOFF == true){
            elapsedSeconds = difftime( time( NULL), startTime);
            cout << "There are " << TotalSecondsToPlay - elapsedSeconds << " seconds left." << endl;
        }
        //increments what turn your on
        turn++;

    }
//information that gets displayed at end of program
    cout << "I let you finish your last move. Time is up!" << endl;
    cout << "Your Final score is: " << score << endl;

    return 0;
}//end main()