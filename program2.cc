#include <iostream>
#include <ctype.h>
using namespace std;

/*Author: Veronica Kalicki
  Program: #2, Traffic
  TA:  Moumita Samanta , Tues 9
  September 29, 2017
*/
//----------------------------------------------------------------------------------------------------------------------
// Displaying Instructions for User
void displayInstructions()
{
    cout << "Welcome to the traffic game!                          " << endl
         << "                                                      " << endl
         << "Move the vehicles so that the Red car (RR) can exit   " << endl
         << "the board to the right. Each move should be of the    " << endl
         << "of the form:   CDN   where:                           " << endl
         << "   C  is the vehicle to be moved                      " << endl
         << "   D  is the direction (u=up, d=down, l=left or r=right)" << endl
         << "   N  is the number of squares to move it             " << endl
         << "For example GR2  means move the G vehicle to the right" << endl
         << "2 squares.  Lower-case input such as   gr2  is also   " << endl
         << "accepted.  Enter '-' to reset board, or 'x' to exit.  " << endl;
}//end displayInstructions()
//----------------------------------------------------------------------------------------------------------------------
// Global Variables Initialized
char  p1, p2, p3, p4, p5, p6,
        p7, p8, p9,p10,p11,p12,
        p13,p14,p15,p16,p17,p18,
        p19,p20,p21,p22,p23,p24,
        p25,p26,p27,p28,p29,p30,
        p31,p32,p33,p34,p35,p36;

//----------------------------------------------------------------------------------------------------------------------
//Displays my header info when called in int main
void headerInfo(){
    cout << "Author: Veronica Kalicki" << endl;
    cout << "Program: #2, Traffic" << endl;
    cout << "TA:  Moumita Samanta , Tuesday 9 am" << endl;
    cout << "September 29, 2017" << endl << endl;

}
//----------------------------------------------------------------------------------------------------------------------
//This function displays the board when called
void displayBoard( char p1 ,char p2 ,char p3 ,char p4 ,char p5 ,char p6 ,
                   char p7 ,char p8 ,char p9 ,char p10 ,char p11 ,char
                   p12 ,char p13 ,char p14 ,char p15 ,char p16 ,char p17 ,
                   char p18 ,char p19 ,char p20 ,char p21 ,char p22 ,char p23 ,
                   char p24 ,char p25 ,char p26 ,char p27 ,char p28 ,char p29 ,
                   char p30 ,char p31 ,char p32 ,char p33 ,char p34 ,char p35 ,char p36){
    cout << " - " << "- " << "- " << "- " << "- " << "- " << "- " << endl;
    cout << "| " << p1 << ' ' <<  p2 << ' ' << p3 << ' ' << p4 << ' ' << p5 << ' ' << p6 << " |" << endl;
    cout << "| " << p7 << ' ' << p8 << ' ' << p9 << ' ' << p10 << ' ' << p11 << ' ' << p12 << " |" << endl;
    cout << "| " << p13 << ' ' << p14 << ' ' << p15 << ' ' << p16 << ' ' << p17 << ' ' << p18  << endl;
    cout << "| " << p19 << ' ' << p20 << ' ' << p21 << ' ' << p22 << ' ' << p23 << ' ' << p24 << " |" << endl;
    cout << "| " << p25 << ' ' << p26 << ' ' << p27 << ' ' << p28 << ' ' << p29 << ' ' << p30 << " |" << endl;
    cout << "| " << p31 << ' ' << p32 << ' ' << p33 << ' ' << p34 << ' ' << p35 << ' ' << p36 << " |" << endl;
    cout << " - " << "- " << "- " << "- " << "- " << "- " << "- " << endl;

}
//----------------------------------------------------------------------------------------------------------------------
//this finds the amount of characters in the row and returns the number of characters
int characterCount (char letter,char p1,char p2,char p3,char p4,char p5,char p6){
    int letterSum = 0;

    if (p1 == letter){
        letterSum += 1;
    }
    if (p2 == letter){
        letterSum += 1;
    }
    if (p3 == letter){
        letterSum += 1;
    }
    if (p4 == letter){
        letterSum += 1;
    }
    if (p5 == letter){
        letterSum += 1;
    }
    if (p6 == letter){
        letterSum += 1;
    }

    return letterSum; // returns lettersum as a number
}
//----------------------------------------------------------------------------------------------------------------------
//this moves the characters
void handlePieces(char car, char &r1, char &r2, char &r3, char &r4, char &r5, char &r6, int legnth, char &direction) {
    char temp;  // assigns a temp integer that temporarily places the letter from beggining cordinate
    if (direction == 'R' || direction == 'D') {  //finds out if the user input is right or down and runs this section of code
        if (legnth == 2) {   //checks to see how long the character is, ie if its 2 then GG can be moved if GGG then it wont
            if (car == r1) {  //checks what is in the first cordiante
                if (r3 == '.') {   //checks to see what is 2 cordinates away
                    //moves everything from the second cordinate to the third
                    temp = r2;
                    r2 = r3;
                    r3 = temp;
                    //moves everything from first to second
                    temp = r1;
                    r1 = r2;
                    r2 = temp;
                } else {
                    cout << " *** Move was attempted, but couldn't be completed. ***" << endl;  //error checking to see if another character is in way
                }
                //if the letter is on spot 2 moves it to the right
            } else if (car == r2) {
                if (r4 == '.') {
                    temp = r3;
                    r3 = r4;
                    r4 = temp;

                    temp = r2;
                    r2 = r3;
                    r3 = temp;
                } else {
                    cout << " *** Move was attempted, but couldn't be completed. ***" << endl; //error checking
                }
                // if the char is on spot 3 then moves it to the right
            } else if (car == r3) {
                if (r5 == '.') {
                    temp = r4;
                    r4 = r5;
                    r5 = temp;

                    temp = r3;
                    r3 = r4;
                    r4 = temp;
                } else {
                    cout << " *** Move was attempted, but couldn't be completed. ***" << endl; //error checking
                }
            } else if (car == r4) {
                if (r6 == '.') {
                    temp = r5;
                    r5 = r6;
                    r6 = temp;

                    temp = r4;
                    r4 = r5;
                    r5 = temp;
                } else {
                    cout << " *** Move was attempted, but couldn't be completed. ***" << endl; //error checking
                }

            } else {
                cout << " *** Move was attempted, but couldn't be completed. ***" << endl; // any other character out of bounds displays error
            }
        }
        //set of instructions if character is 3 long
        if (legnth == 3) {
            if (car == r1) {  // checks the position and moves it to right
                if (r4 == '.') { //if there is nothing on r4 the character will move
                    temp = r3;
                    r3 = r4;
                    r4 = temp;

                    temp = r2;
                    r2 = r3;
                    r3 = temp;

                    temp = r1;
                    r1 = r2;
                    r2 = temp;
                } else {
                    cout << " *** Move was attempted, but couldn't be completed. ***" << endl; //if something on spot 4 then it will return an error message
                }

            } else if (car == r2) {  // if character is on spot 2 will move them to the right of spot 2
                if (r5 == '.') {  // checks to see what is on space 5
                    temp = r4;
                    r4 = r5;
                    r5 = temp;

                    temp = r3;
                    r3 = r4;
                    r4 = temp;

                    temp = r2;
                    r2 = r3;
                    r3 = temp;
                } else {
                    cout << " *** Move was attempted, but couldn't be completed. ***" << endl;  //if anything is on space 5 then it returns error message
                }
            } else if (car == r3) {  // checks spot 3 if there is a character then it moves it to the right
                if (r6 == '.') {  // checks to see spot 6 if there is nothing there then it will accept a move command
                    temp = r5;
                    r5 = r6;
                    r6 = temp;

                    temp = r4;
                    r4 = r5;
                    r5 = temp;

                    temp = r3;
                    r3 = r4;
                    r4 = temp;
                } else {
                    cout << " *** Move was attempted, but couldn't be completed. ***" << endl; // if something is there then it will return error
                }
            } else {  // if there is any character out of bounds it wont move the character and it will display a error message
                cout << " *** Move was attempted, but couldn't be completed. ***" << endl;
            }
        } // end of char 3
    } else if (direction == 'L' || direction == 'U' ) {  //if user input is left or Up runs this section of code
        if (legnth == 2) {  //if legnth is two will move peices that are two long ie GG, not GGG
            if ( car == r1){  // if there is a character on spot 1 then it wont move anything to right and returns an error
                cout << " *** Move was attempted, but couldn't be completed. ***" << endl;
            } else if ( car == r2){ // checks to see if there is a character on spot 2
                if (r1 == '.'){  // if nothing is on spot one and the char is on spot 2 then it moves the character left
                    temp = r2;
                    r2 = r1;
                    r1 = temp;

                    temp = r3;
                    r3 = r2;
                    r2 = temp;
                } else {
                    cout << " *** Move was attempted, but couldn't be completed. ***" << endl;  // if there is something on spot 1 then it will return an error message
                }

            } else if ( car == r3) { //checks for a character on spot 3
                if (r2 == '.') { //if no char on spot 2 then the characters will move to the left
                    temp = r3;
                    r3 = r2;
                    r2 = temp;

                    temp = r4;
                    r4 = r3;
                    r3 = temp;

                }else {
                    cout << " *** Move was attempted, but couldn't be completed. ***" << endl; // if there is a character in the way then it will return error message
                }
            } else if ( car == r4) {  // checks for character on spot 4
                if (r3 == '.') { // if spot 3 is blank then it moves the letter from spot 4 to spot 3
                    temp = r4;
                    r4 = r3;
                    r3 = temp;

                    temp = r5;
                    r5 = r4;
                    r4 = temp;
                } else {
                    cout << " *** Move was attempted, but couldn't be completed. ***" << endl; // if there is a letter on spot 3 then it returns error
                }
            } else if ( car == r5){ // checks to spot if there is a character on spot 5
                if (r4 == '.'){   // checks if there is anything on spot 4 if not then moves letter from spot 5 to spot 4
                    temp = r5;
                    r5 = r4;
                    r4 = temp;

                    temp = r6;
                    r6 = r5;
                    r5 = temp;

                } else {
                    cout << " *** Move was attempted, but couldn't be completed. ***" << endl; // if there is something in spot 4 then returns error
                }
            }
        } else if( legnth == 3){  // if the character is 3 characters or longer then runs this code
            if ( car == r1){ // checks to see if character is on spot 1 if so returns error
                cout << " *** Move was attempted, but couldn't be completed. ***" << endl;
            } else if ( car == r2){  // checks to see if there is a letter on spot 2 if so runs code
                if (r1 == '.'){  // if there is nothing on spot 1 then it will move spot 2 to spot 1
                    temp = r2;
                    r2 = r1;
                    r1 = temp;

                    temp = r3;
                    r3 = r2;
                    r2 = temp;

                    temp = r4;
                    r4 = r3;
                    r3 = temp;
                } else {
                    cout << " *** Move was attempted, but couldn't be completed. ***" << endl;  // if something is in the way returns an error
                }



            } else if ( car == r3){  // checks to see if there is a letter in spot 3 if so runs code
                if (r2 == '.'){  // checks if spot 2 is blank if so moves spot 3 over to spot 2
                    temp = r3;
                    r3 = r2;
                    r2 = temp;

                    temp = r4;
                    r4 = r3;
                    r3 = temp;

                    temp = r5;
                    r5 = r4;
                    r4 = temp;
                } else {
                    cout << " *** Move was attempted, but couldn't be completed. ***" << endl; //if letter in the way runs error
                }
            } else if (car == r4) {  // checks for letter on spot 4 if so runs code
                if (r3 == '.') {  // if spot 3 doesnt have a letter then moves spot 4 to spot 3
                    temp = r4;
                    r4 = r3;
                    r3 = temp;

                    temp = r5;
                    r5 = r4;
                    r4 = temp;

                    temp = r6;
                    r6 = r5;
                    r5 = temp;
                } else {
                    cout << " *** Move was attempted, but couldn't be completed. ***" << endl; // if there is a character in spot 3 then returns error
                }
            }
        }
    }
}
//----------------------------------------------------------------------------------------------------------------------
// this function finds the row and sends the info to be moved and loops if for how many times the user asked
void MakeMove (char car, char direction, int spaces){
    // row 1-6
    if (characterCount( car, p1,p2,p3,p4,p5,p6) >= 2){
        for(int i = 1; i <= spaces; i++){
            handlePieces(car, p1,p2,p3,p4,p5,p6,characterCount( car, p1,p2,p3,p4,p5,p6), direction);
        }
        // row 7-12
    } else if (characterCount( car, p7,p8,p9,p10,p11,p12) >= 2){
        for(int i = 1; i <= spaces; i++){
            handlePieces(car, p7,p8,p9,p10,p11,p12, characterCount( car, p7,p8,p9,p10,p11,p12), direction);
        }
        // row 13-18
    } else if (characterCount( car, p13,p14,p15,p16,p17,p18) >= 2){
        for(int i = 1; i <= spaces; i++){
            handlePieces(car, p13,p14,p15,p16,p17,p18, characterCount( car, p13,p14,p15,p16,p17,p18), direction);
        }
        // row 19-24
    } else if (characterCount( car, p19,p20,p21,p22,p23,p24) >= 2){
        for(int i = 1; i <= spaces; i++){
            handlePieces(car, p19,p20,p21,p22,p23,p24, (characterCount( car, p19,p20,p21,p22,p23,p24)), direction);
        }
        // row 25- 30
    } else if (characterCount( car, p25,p26,p27,p28,p29,p30) >= 2){
        for(int i = 1; i <= spaces; i++){
            handlePieces(car, p25,p26,p27,p28,p29,p30, (characterCount( car, p25,p26,p27,p28,p29,p30)), direction);
        }
        //row 31-36
    } else if (characterCount( car, p31,p32,p33,p34,p35,p36) >= 2){
        for(int i = 1; i <= spaces; i++){
            handlePieces(car, p31,p32,p33,p34,p35,p36, (characterCount( car, p31,p32,p33,p34,p35,p36)), direction);
        }
        //column 1-31
    } else if (characterCount( car, p1,p7,p13,p19,p25,p31) >= 2){
        for(int i = 1; i <= spaces; i++){
            handlePieces(car, p1,p7,p13,p19,p25,p31, (characterCount( car, p1,p7,p13,p19,p25,p31)), direction);
        }
        //column 2-32
    } else if (characterCount( car, p2,p8,p14,p20,p26,p32) >= 2){
        for(int i = 1; i <= spaces; i++){
            handlePieces(car, p2,p8,p14,p20,p26,p32,characterCount( car, p2,p8,p14,p20,p26,p32), direction);
        }
        // column 3-33
    }else if (characterCount( car, p3,p9,p15,p21,p27,p33) >= 2){
        for(int i = 1; i <= spaces; i++){
            handlePieces(car, p3,p9,p15,p21,p27,p33,characterCount( car, p3,p9,p15,p21,p27,p33), direction);
        }
        // column 4-34
    }else if (characterCount( car, p4,p10,p16,p22,p28,p34) >= 2){
        for(int i = 1; i <= spaces; i++){
            handlePieces(car, p4,p10,p16,p22,p28,p34, characterCount( car, p4,p10,p16,p22,p28,p34), direction);
        }
        // column 5-35
    }else if (characterCount( car, p5,p11,p17,p23,p29,p35) >= 2){
        for(int i = 1; i <= spaces; i++){
            handlePieces(car, p5,p11,p17,p23,p29,p35, characterCount( car, p5,p11,p17,p23,p29,p35), direction);
        }
        // column 6-36
    }else if (characterCount( car, p6,p12,p18,p24,p30,p36) >= 2){
        for(int i = 1; i <= spaces; i++){
            handlePieces( car, p6,p12,p18,p24,p30,p36,characterCount( car, p6,p12,p18,p24,p30,p36), direction);
        }
    }
}
//----------------------------------------------------------------------------------------------------------------------
//asks for user input to create NEW board.
void newBoard (){
    cout << "Enter a letter or a period.";
    cin >> p1;
    cout << "Enter a letter or a period.";
    cin >> p2;
    cout << "Enter a letter or a period.";
    cin >> p3;
    cout << "Enter a letter or a period.";
    cin >> p4;
    cout << "Enter a letter or a period.";
    cin >> p5;
    cout << "Enter a letter or a period.";
    cin >> p6;
    cout << "Enter a letter or a period.";
    cin >> p7;
    cout << "Enter a letter or a period.";
    cin >> p8;
    cout << "Enter a letter or a period.";
    cin >> p9;
    cout << "Enter a letter or a period.";
    cin >> p10;
    cout << "Enter a letter or a period.";
    cin >> p11;
    cout << "Enter a letter or a period.";
    cin >> p12;
    cout << "Enter a letter or a period.";
    cin >> p13;
    cout << "Enter a letter or a period.";
    cin >> p14;
    cout << "Enter a letter or a period.";
    cin >> p15;
    cout << "Enter a letter or a period.";
    cin >> p16;
    cout << "Enter a letter or a period.";
    cin >> p17;
    cout << "Enter a letter or a period.";
    cin >> p18;
    cout << "Enter a letter or a period.";
    cin >> p19;
    cout << "Enter a letter or a period.";
    cin >> p20;
    cout << "Enter a letter or a period.";
    cin >> p21;
    cout << "Enter a letter or a period.";
    cin >> p22;
    cout << "Enter a letter or a period.";
    cin >> p23;
    cout << "Enter a letter or a period.";
    cin >> p24;
    cout << "Enter a letter or a period.";
    cin >> p25;
    cout << "Enter a letter or a period.";
    cin >> p26;
    cout << "Enter a letter or a period.";
    cin >> p27;
    cout << "Enter a letter or a period.";
    cin >> p28;
    cout << "Enter a letter or a period.";
    cin >> p29;
    cout << "Enter a letter or a period.";
    cin >> p30;
    cout << "Enter a letter or a period.";
    cin >> p31;
    cout << "Enter a letter or a period.";
    cin >> p32;
    cout << "Enter a letter or a period.";
    cin >> p33;
    cout << "Enter a letter or a period.";
    cin >> p34;
    cout << "Enter a letter or a period.";
    cin >> p35;
    cout << "Enter a letter or a period.";
    cin >> p36;

}

// start of main call
int main() {
    //sets the values for the global characters
    p1='G'; p2='G'; p3='.'; p4='.'; p5='.'; p6='Y';
    p7='P'; p8='.'; p9='.';p10='B';p11='.';p12='Y';
    p13='P';p14='R';p15='R';p16='B';p17='.';p18='Y';
    p19='P';p20='.';p21='.';p22='B';p23='.';p24='.';
    p25='O';p26='.';p27='.';p28='.';p29='T';p30='T';
    p31='O';p32='.';p33='F';p34='F';p35='F';p36='.';

    //string that gets user input during loop
    char userInputColor;  // variable for user to choose what car to move
    char userInputDirection; // allows the user to choose what direction to move
    int userInputSpaces; //asks the user how many spaces they want to move
    int counter = 1;  //counter for the ammount of moves


    headerInfo(); // displays my header info from the funciton above
    displayInstructions(); //dislays the instructions
    // displays board with characters
    do {
        displayBoard(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10,
                     p11, p12, p13, p14, p15, p16, p17, p18,
                     p19, p20, p21, p22, p23, p24, p25, p26,
                     p27, p28, p29, p30, p31, p32, p33, p34,
                     p35, p36);
        //prints out asking user for their move
        cout << counter << ". Your move -> ";
        //asks for user input to change the location of pieces
        cin >> (userInputColor);
        //capitalizes user letter input
        userInputColor = toupper(userInputColor);
        // if user puts X as user input color, then it will end the program
        if (userInputColor == 'X'){
            return 0;
        }
        // if the user inputs '-' then it will create a new board a reset the loop
        if (userInputColor == '-'){
            newBoard();
            continue;
        }
        //gets second part of user input
        cin >> userInputDirection >> userInputSpaces;
        //capitalizes the letter user input
        userInputDirection = toupper(userInputDirection);

        MakeMove(userInputColor,userInputDirection, userInputSpaces);
        // if the user inputs "X" then it exits the game
        counter+=1; //each time the loop runs it adds one to the counter when asking for a move
    } while ( p18 != 'R'); // ends the program when r reaches position 18

    cout << endl;
    cout << "Thank you for playing.  Exiting..." << endl;  // outputs when user wins

    return 0;
}