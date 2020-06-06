/*Author:  Kevin Barrett and Veronica Kalicki
Lab:     Tuesday 9am and 10am
Program: #3, 0/1 Guessing Game

Welcome to the 0/1 guessing game!

Enter 0 or 1, trying to outsmart the computer, which is going to
attempt to forecast your guesses.  On each move the score indicator
moves to the right if the computer guesses correctly, and moves
to the left if the computer does not.
    Enter 't' to toggle displaying the data table.
    Enter 'r' to reset the board.
    Enter 'x' to exit.
Good luck, you'll need it!


Computer          Human
x---------x+++++++++x
          ^
1. Your input: 0
   Human gets a point.
 */


#include <iostream>
#include <iomanip>
using namespace std;



//the below code is used to display the board at the beginning of the game
void displayInfo(){
    cout << "Author Kevin Barrett and Veronica Kalicki" << endl;
    cout << "Lab: Tuesday 9am and 10am" << endl;
    cout << "Program: #3, 0/1 Guessing Game" << endl << endl;
    cout << "Welcome to the 1/1 guessing game!" << endl << endl;
    cout << "Enter 0 or 1, trying to outsmart the computer, which is going to" << endl;
    cout << "attempt to forecast your guesses. On each move the score indicator " << endl;
    cout << "moves to the right if the computer guesses correctly, and moves " << endl;
    cout << "to the left if the computer does not." << endl;
    cout << "    Enter 't' to toggle displaying the data table." << endl;
    cout << "    Enter 'r' to reset the board." << endl;
    cout << "    Enter 'x' to exit." << endl;
    cout << "Good luck, you'll need it!" << endl << endl << endl;
}

//shows the board and score piece is located
void DisplayBoard(int counter, int score){
    cout << "Computer          Human" << endl;
    cout <<  "x---------x+++++++++x" << endl;
    for (int i = 1; i <= score; i++){
        cout << ' ';                    //places spaces for every point the computer
                                        // has over the human and subtracts spaces for points over computer
    }
    cout << '^' << endl; // the arrow is placed after all the spaces
    cout << counter << ": Your Input: "; //asks for the user input
}
// funttion that displays the table and information from past choices
void displayTable(int moveTable[][2], int binary, int guessesList[3],string tableguess[], int computerGeuss) {
    cout << "      0   " << "1" << endl;
    cout << "    --- ---" << endl;
    for (int column = 0; column < 8; column++) {
        cout << tableguess[column];
        for (int row = 0; row < 2; row++) {
            cout << setw(4) << moveTable[column][row];
        }cout << endl;
    }
    cout << "Previous three: " << guessesList[0] << guessesList[1] << guessesList[2] << "." << "    "; //displays the last 3 numbers choosen
    cout << "ForeCast:" << computerGeuss << endl; // displays the computers geuss
}
//this funtion chooses what the computer is geussing
void computerGeussUpdate(int binary, int moveTable[][2], int ourGuess, int counter, int &computer, int &human, int &computerGuess  ){
        //for the first 3 geusses human gets the first three points
    if(counter <= 3){
        human++;
        cout << "Human Scores a Point" << endl; // displays if the human got the poiint
    }
    if (moveTable[binary][0] > moveTable[binary][1]){  //if the number of numbers in the zero row are larger the computer geusses zero
        computerGuess = 0;
    }else if (moveTable[binary][0] < moveTable[binary][1]){ //if the number of numbers in the one row are larger then the computer geusses one
        computerGuess = 1;
    }else if (moveTable[binary][0] == moveTable[binary][1]){ // if the numbers are equal then the computer geusses the opposite of the human
        computerGuess =  !(ourGuess - '0');
        }
    if (counter > 3 && (ourGuess - '0') != computerGuess){  // if the computer and human geuss are opposite human gains a point
        human++;
        cout << "Human Scores a Point" << endl;  // displays if the human got the point
    } else if( counter > 3 && (ourGuess - '0') == computerGuess){ //if the human and computer geuss are the same the computer gets a point
        computer++;
        cout << "Computer Scores a Point" << endl; // displays if the computer recieved the point
    }
}
//this funtion updates the numbers in the table
void tableUpdate(int binary, int moveTable[][2],char humangeuss){
    if ((humangeuss - '0') == 0){
        moveTable[binary][0]++;
    }else if ((humangeuss - '0') == 1){
        moveTable[binary][1]++;
    }

}

// this function places the new user int in the array and moves the others down one and removes the last int
void arrayAdd(int guessesList[3], char humanGuess){
    guessesList[0] = guessesList[1];
    guessesList[1] = guessesList[2];
    guessesList[2] = humanGuess - '0';
}
    // takes all the numbers in the array and finds the binary value of them all
    int binaryfucntion(int guesses[],int sum = 0){

        if (guesses[0] == 1){
            sum += 4;
        } else {sum +=0;}
        if (guesses[1] == 1){
            sum +=2;
        }else {sum += 0;}
        if (guesses[2] == 1){
            sum += 1;
        } else { sum += 0;}
        return sum;
    }
void resetFunction(int guessList[],int &counter, int &computerScore, int &humanScore){

    counter = 1;
    computerScore = 0;
    humanScore = 0;
    guessList[3] = {0};
}

//------------------------------------------------------------------------------------------------------------------------

int main() {
    int ourGuesses[3] = {0,0,0};    // holds our 3 guesses in the array
    int moveTable[8][2] = {0};
    string tableguess[] = {"000","001", "010","011","100","101","110","111"};  //used to show the binary numbers in the table
    int score, humanScore, computerScore, sum , table, computerGuess; // all my ints that are used
    char humanGuess; //human guess that is used to accept all input
    int counter = 1; // counter to count how many times the user has tried to beat computer
    humanScore = score = computerScore = sum = table =computerGuess = 0;


    //call to displayinfo function that displays the output from the function
    displayInfo();

        // runs until somebody has more than 10 points over the other
    while (score >= 0 && score <= 19) {
        // this is used to get score from each person and keep the arrow in the center at start
        score = (humanScore - computerScore) + 10;
        // displays the board showing the arrow and who is winning
        DisplayBoard(counter, score);
        // this is where the human puts their geuss
        cin >> humanGuess;
        cout << endl;
        // will only accept user input if its a 1 or zero if not it ignores the input
        if(humanGuess == '1' || humanGuess == '0') {
            //this goes to a function that finds the computer Geuss
            computerGeussUpdate(binaryfucntion(ourGuesses,sum), moveTable, humanGuess, counter, computerScore, humanScore, computerGuess);
            // this goes to a function that updates the numbers in the table
            tableUpdate(binaryfucntion(ourGuesses,sum), moveTable, humanGuess);
            // this adds the numbers to the array when user enters new input
            arrayAdd(ourGuesses, humanGuess);
            counter++;

        }
        // toggles the table on and off if its 1 its on if its zero its off
        if (table == 0 && humanGuess == 't' || humanGuess =='T'){
            table = 1;
        } else if (table == 1 && humanGuess == 't' || humanGuess =='T'){
            table = 0;
        }
        //displays the table and previous three quesses
        if (table == 1) {
            displayTable(moveTable,binaryfucntion(ourGuesses,sum),ourGuesses, tableguess, computerGuess);
        }
        //displays if the computer or human is about to win with a message
        if (score == 14){
            cout <<"    Humans are superior!!!!!" << endl;
        } else if (score == 6){
            cout << "   Silicon rules!!!!!!!" << endl;
        }
        //inputting x or X will exit the game
        if (humanGuess =='x'|| humanGuess == 'X'){
            break;
        }
        if (humanGuess == 'r' || humanGuess == 'R'){
            resetFunction(ourGuesses,counter, computerScore,humanScore);
        }


    }
    // displays a specific message depending on who won
    if (score >=19){
        cout << "Human has won";
    }else if(score <= 0){
       cout << "Computer has won";
    } else  cout << "Thanks for playing";
    cout << "Please Press E";
    char endGame;
    cin >> endGame;
    //allows the user to see who won the game at the end
    while (endGame != 'E'){
        cout << "Please Press 'E'";
        cin >> endGame;
    }

    return 0;
}