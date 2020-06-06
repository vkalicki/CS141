#include <iostream>
#include <ctime>  // To ensure random variables by having different time in computer.
#include <iomanip> // To set width setw(2) within the code.
using namespace std; // It makes it so that one doesn't need to put std before every statement

int main() {
    // This writes out my information
    cout << "Program #1: Guess It" << endl;
    cout << "Author: Veronica Kalicki" << endl;
    cout << "Lab: Tues 9am, Moumita Samanta"<< endl;
    cout << "Date: September 11th, 2017" << endl;
    cout << "System: C++ in iCloud 9" << endl << endl ;

    // These are my variables
        int numberLoops, loopCharacter, staticSymbol ;
        char userInput;

    srand(time(0)); //Generates a random a unique seed each time the program runs

    // Gives a letter of the alphabet and it becomes a special character for the table.
    staticSymbol = rand() %26 ;
    if (staticSymbol % 2 == 0){
        staticSymbol = staticSymbol + 'A' ; //if even Capital.
    } else {staticSymbol = staticSymbol + 'a';} // if odd Lower Case.

    // Generates the table beginning at 99 to 0.
    for (numberLoops = 99 ; numberLoops >= 0 ; --numberLoops ){

        // Gives a random letter to each number in the loop. (Not the special character).
        loopCharacter = rand() %26 ;
        if (loopCharacter % 2 == 0) {
            loopCharacter = loopCharacter + 'A'; // if even Capital.
        } else {loopCharacter = loopCharacter + 'a';} // if odd Lower Case.

      /* For multiples of 9 it prints out the special character and
         if it is not divisible by 9 [by else] it just prints out random letter for each number */
        if (numberLoops % 9 == 0) {
            cout << setw(2) << numberLoops << ":" << char(staticSymbol) << " "; // setw(2) is used to line up columns.
        } else {cout << setw(2) << numberLoops << ":" << char(loopCharacter) << " ";}  //char() is used to convert a number into aletter

        //If numbers divisible by 10 it creates a new line.
        if (numberLoops % 10 == 0) {
            cout << endl; }
    } // end of for loop

    //Prints out instructions
    cout << endl << " 1. Choose any two-digit number in the table above (e.g. 73)." << endl ;
    cout << " 2. Subtract its two digits from itself (e.g. 73 - 7 - 3 = 63). " << endl;
    cout << " 3. Find this new number (e.g. 63) and remember the letter next to it." << endl;
    cout << " 4. Now press 'r' and I'll read your mind... " ;
    cin >> userInput; //Accepts user Input

    //While userInput is not 'r' it asks for 'r'.
    while (userInput != 'r') {
        cout << "Please select r" << endl;
        cin >> userInput ;} //Allows for userInput to be 'r'.

    //Tells user what the [variable] special character was. Recall: Special character is randomized each time.
    cout << "You selected the character: " << char(staticSymbol) << endl;

    return 0; //ends program.
}