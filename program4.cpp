

/* ------------------------------------------------
 * Graphical Traffic       *
 *
 * Class: CS 141, Fall 2017.  Tues 9am and 10am lab
 * System: Windows 10, Qt Creator
 * Author: and Veronica Kalicki and Kevin Barrett
 *
 *
 * -------------------------------------------------
 */
//
#include <iostream>
#include "gobjects.h"  // for all graphics objects
#include <fstream>        // For file input
#include <cstring>        // for toUpper
#include <string>
using namespace std;
//----------------------------------------------------------------------------------------------
// this information gets displayed when the user calls it from int main
void displayInfo(){
    cout << "Author:  Veronica Kalicki and Kevin Barrett " << endl;
    cout << "Lab:     Tuesday 9am and 10am" << endl;
    cout << "Program: #4,Graphical Traffic" << endl << endl;
    cout << "Welcome to the traffic game!" << endl;
    cout << "Move the vehicles so that the Red car (RR) can exit" << endl;
    cout << "the board to the right. Each move should be of the" << endl;
    cout << "of the form:   CDN   where:" << endl;
    cout << "   C  is the vehicle to be moved" << endl;
    cout << "   D  is the direction (u=up, d=down, l=left or r=right)" << endl;
    cout << "   N  is the number of squares to move it" << endl;
    cout << "For example GR2  means move the G vehicle to the right" << endl;
    cout << "2 squares.  Lower-case input such as   gr2  is also" << endl;
    cout << "accepted.  Enter '-' to reset board, or 'x' to exit." << endl;
}

//----------------------------------------------------------------------------------------------
//class used to get information from the file
class Vehicle
{
public:
    //constructors
    Vehicle( ){}
    Vehicle( char theColor, char theDirection, int theX, int theY, int theLength) {
        switch(theColor){

        case('G'):color = "green"; break;
        case('R'):color = "red"; break;
        case('B'):color = "blue"; break;
        case('Y'):color = "yellow"; break;
        case('C'):color = "Cyan"; break;
        case('M'):color = "magenta"; break;
        case('O'):color = "orange"; break;
        case('P'):color = "pink"; break;
        default:color ="gray"; break;
        }

    this->direction = theDirection;
    this->x = theX; this->y = theY; this->length = theLength;
}
    //information is stored here when its inputted
    void setValues(string theColor, char theDirection, int theX, int theY, int theLength){
        this->color = theColor; this->direction = theDirection;
        this->x = theX; this->y = theY; this->length =theLength;
    }

    string getColor() { return color; }
            char getDirection() { return direction; }
            int getX() { return x; }
            int getCol() { return y; }
            int getLength() { return length; }


private:
    string color;
    char direction;
    int x,y,length;

};
//----------------------------------------------------------------------------------------------
//detects if the direction being moved is Up or Down
int MoveUpDown(char direction, int numMoves){
int sum = 0;
//determines how many times the array will move
    for(int i= 0; i < numMoves;i++){
       //determines if the array is moving up
    if(direction == 'U'){
      sum= sum - 1;
    }
    //determines if the array is moving down
    if(direction == 'D'){
      sum = sum + 1;
    }
  }
    return sum;  //returns a sum that gets added to the array to change the locations
}

//---------------------------------------------------------------------------------------
//function that capitalizes all the user input according to size of string and returns the string
string upperCase(string input){
    for(int i = 0; i < input.length(); i++){
        input[i] = toupper(input[i]);
    }
    return input;
}

//----------------------------------------------------------------------------------------------
//detects if the direction being moved is Left or Right
int MoveLeftRight(char direction, int numMoves){
int sum = 0;
//determines how many times the array will move
for(int i= 0; i < numMoves;i++){
 //determines if the array will go left
if(direction == 'L'){
        sum=sum - 1;
    }
//determines if it is going right
    if(direction == 'R'){
        sum= sum + 1;
    }
 }
return sum;  //returns the sum that gets added to teh array to change locations
}

//----------------------------------------------------------------------------------------------
//the function that takes the input from the user to make the array move
bool makeMove(char color, char direction, int moves, char array[6][6]){
 int upDown,leftRight;
 //below are errors that will pop up when and if they occur
 string onTopError = "Attempt is made to move a piece on top of another piece.  Please retry.";
 string outOfBoundsError = "Attempt is made to move a piece off the edge of the board.  Please retry.";
 bool error = false;
 bool error2 = false;
 //determines the total number of times the array will move in a specific direction
 if (direction =='L' || direction =='R'){leftRight = MoveLeftRight(direction,moves);}
 if (direction =='U' || direction == 'D'){upDown = MoveUpDown(direction, moves);}


char arrayReset[6][6];
for (int i = 0; i <6;i++){
    for(int j = 0; j < 6; j++){
        arrayReset[i][j] = array[i][j];
    }
}
//if the array moves to the right then it will move as many times that have been added to LeftRight variable
 if (direction =='R'){
     for (int i = 5; i >= 0;i--){
       for(int j = 5; j >= 0; j--){
            if (color == array[i][j]){
                if((j+(leftRight)) > 5){ // checks to see if code is out of bounds
                    error2 = true;
                    break;
                }
                if(array[i][j+ (leftRight)] != '.'){ //checks to see if code is on top of another piece
                    error = true;
                    break;
                }
                char temp = array[i][j];
                 array[i][j] = array[i][j+ (leftRight)];
                array[i][j+ (leftRight)] = temp;
            }
        }
}
}
 //if the array moves to the down then it will move as many times that have been added to UpDown variable
 if ( direction =='D'){
     for (int i = 5; i >= 0;i--){
       for(int j = 5; j >= 0; j--){
            if (color == array[i][j]){
                if((i+(upDown)) > 5){  // checks to see if code is out of bounds
                    error2 = true;
                    break;
                }
                if(array[i+(upDown)][j] != '.'){  //checks to see if code is on top of another piece
                    error = true;
                    break;
                }
                char temp = array[i][j];
                 array[i][j] = array[i+(upDown)][j];
                array[i+(upDown)][j] = temp;
            }
        }
    }
}

 //if the array moves to Up then it will move as many times that have been added to upDown variable
 if (direction =='U' ){
     for (int i = 0; i <6 ;i++){
       for(int j = 0; j < 6; j++){
            if (color == array[i][j]){
                if((i+(upDown)) < 0){  // checks to see if code is out of bounds
                    error2 = true;
                    break;
                }
                if(array[i+(upDown)][j] != '.'){  //checks to see if code is on top of another piece
                    error = true;
                    break;
                }
                char temp = array[i][j];
                 array[i][j] = array[i+(upDown)][j];
                array[i+(upDown)][j] = temp;
          }
       }
     }
 }

 //if the array moves to the left then it will move as many times that have been added to LeftRight variable
 if (direction =='L'){
     for (int i = 0; i < 6 ;i++){
       for(int j = 0; j < 6; j++){
            if (color == array[i][j]){
                if((j+(leftRight)) < 0){  // checks to see if code is out of bounds
                    error2 = true;
                    break;
                }
                if(array[i][j+ (leftRight)] != '.'){ //checks to see if code is on top of another piece
                    error = true;
                    break;
                }

                char temp = array[i][j];
                 array[i][j] = array[i][j+ (leftRight)];
                array[i][j+ (leftRight)] = temp;

            }
        }
}
}
 if (error2){ // if error 2 pops up it will tell the user the move was out of bounds and resets the array to what was passed to function
      cout << outOfBoundsError << endl;
      for (int i = 0; i <6;i++){
          for(int j = 0; j < 6; j++){
              array[i][j] = arrayReset[i][j];
          }
      }
      return true;
  }
 if (error){ //if error 1 pops up then it will write out that it was on another peice and sets the array to what was orignially passed
     cout << onTopError << endl;
     for (int i = 0; i <6;i++){
         for(int j = 0; j < 6; j++){
             array[i][j] = arrayReset[i][j];
         }
     }
     return true;

 }

    return false;
 }

//--------------------------------------------------------------------------------------------------------------------
int main() {
    ifstream inputFileStream;  // declare the input file stream
//variable declaration
    char carColor, carDirection;
    int numMoves , counter;
    counter = 1;
    bool badMove = false;
    char array[6][6]= {};
    string userInput;


//displays user info
    displayInfo();

    //sets the array to be all '.' before recieving input that overwrites.
    for (int i = 0; i <6;i++){
        for(int j = 0; j < 6; j++){
            array[i][j] = '.';
        }
    }
//takes the input from the file
    inputFileStream.open("board.txt");
    if( !inputFileStream.is_open()) {
        cout << "Could not find input file board.txt.  Exiting..." << endl;
        exit( -1);
    }
//assigns how many vehicles and how many times the loop will run
    int howManyVehicles;
    inputFileStream >> howManyVehicles;
    Vehicle *vehicles[ 8]; // stores all the vehicles
    char vehicle, direction;
    int xPosition, yPosition, length;
    //the loop assigns the variables into the array to be used for moving the peices as well as putting them in the class
    for( int i=0; i<howManyVehicles; i++) {
        inputFileStream >> vehicle >> direction >> xPosition >> yPosition >> length;

        if (direction == 'V'){
            for( int i = 0; i <length;i++){
                array[xPosition+i-1][yPosition-1] = vehicle;
            }
        }
        if (direction == 'H'){
            for( int i = 0; i <length;i++){
                array[xPosition-1][yPosition-1+i] = vehicle;
            }
        }

        vehicles[ i] = new Vehicle( vehicle,direction, xPosition, yPosition, length);
    }
    //info that was used to ensure fileinput was used
    /*
   for (int i = 0; i <6;i++){
        for(int j = 0; j < 6; j++){
            cout <<array[i][j];
        }
        cout << endl;
    }
    */
// Create a graphics window, which will be used to draw graphical shapes
GWindow graphicsWindow(300, 300);   // Set the size
graphicsWindow.setWindowTitle("CS 141 Lab Sample Drawing");

//---------------------------------------------------------------------------------------
// Create a rectangle
GRect *outerBoard = new GRect(10,10,270,270);
outerBoard->setFilled(true);
outerBoard->setColor("darkgray");
// Add it to the graphics window.  Without this it will exist, but will not show up.
graphicsWindow.add(outerBoard);
//below creates the user board
GRect *innerBoard = new GRect(20,20,250,250);
innerBoard->setFilled(true);
innerBoard->setColor("gray");
graphicsWindow.add(innerBoard);
//displays the user exit
GRect *vehicleExit = new GRect( 270,100,10,50);
vehicleExit->setFilled(true);
vehicleExit->setColor("lightgray");
graphicsWindow.add(vehicleExit);
//below code puts the lines in the board
GRect *line1 = new GRect(20,20,10,250);
line1->setFilled(true);
line1->setColor("lightgray");
graphicsWindow.add(line1);

GRect *line2 = new GRect(60,20, 10,250);
line2->setFilled(true);
line2->setColor("lightgray");
graphicsWindow.add(line2);

GRect *line3 = new GRect( 100,20, 10,250);
line3->setFilled(true);
line3->setColor("lightgray");
graphicsWindow.add(line3);

GRect *line4 = new GRect(140,20, 10,250);
line4->setFilled(true);
line4->setColor("lightgray");
graphicsWindow.add(line4);

GRect *line5 = new GRect(180,20, 10,250);
line5->setFilled(true);
line5->setColor("lightgray");
graphicsWindow.add(line5);

GRect *line6 = new GRect(220,20, 10,250);
line6->setFilled(true);
line6->setColor("lightgray");
graphicsWindow.add(line6);

GRect *line7 = new GRect(260,20, 10,250);
line7->setFilled(true);
line7->setColor("lightgray");
graphicsWindow.add(line7);

GRect *row1 = new GRect(20,20, 250,10);
row1->setFilled(true);
row1->setColor("lightgray");
graphicsWindow.add(row1);

GRect *row2 = new GRect(20,60, 250,10);
row2->setFilled(true);
row2->setColor("lightgray");
graphicsWindow.add(row2);

GRect *row3 = new GRect(20,100, 250,10);
row3->setFilled(true);
row3->setColor("lightgray");
graphicsWindow.add(row3);

GRect *row4 = new GRect(20,140, 250,10);
row4->setFilled(true);
row4->setColor("lightgray");
graphicsWindow.add(row4);

GRect *row5 = new GRect(20,180, 250,10);
row5->setFilled(true);
row5->setColor("lightgray");
graphicsWindow.add(row5);

GRect *row6 = new GRect(20,220, 250,10);
row6->setFilled(true);
row6->setColor("lightgray");
graphicsWindow.add(row6);

GRect *row7 = new GRect(20,260, 250,10);
row7->setFilled(true);
row7->setColor("lightgray");
graphicsWindow.add(row7);
//---------------------------------------------------------------------------------------
//assigns the car to a specific location and names them according to color

GRect *redcar = new GRect( 70,110,70,30);
redcar->setFilled(true);
redcar->setColor("red");
graphicsWindow.add(redcar);

GRect *yellowcar = new GRect(230, 30,  30,110);
yellowcar->setFilled(true);
yellowcar->setColor("yellow");
graphicsWindow.add(yellowcar);

GRect *bluecar = new GRect(150, 70,  30,110);
bluecar->setFilled(true);
bluecar->setColor("blue");
graphicsWindow.add(bluecar);

GRect *greencar = new GRect( 30, 30,  70, 30);
greencar->setFilled(true);
greencar->setColor("green");
graphicsWindow.add(greencar);

GRect *magentacar = new GRect(30, 70,  30,110);
magentacar->setFilled(true);
magentacar->setColor("magenta");
graphicsWindow.add(magentacar);

GRect *cyancar = new GRect(190,190,  70, 30);
cyancar->setFilled(true);
cyancar->setColor("cyan");
graphicsWindow.add(cyancar);

GRect *orangecar = new GRect(30,190,  30, 70);
orangecar->setFilled(true);
orangecar->setColor("orange");
graphicsWindow.add(orangecar);

GRect *pinkcar = new GRect(110,230, 110, 30);
pinkcar->setFilled(true);
pinkcar->setColor("pink");
graphicsWindow.add(pinkcar);
//---------------------------------------------------------------------------------------

//this code runs as long as there isnt an r in the oppening
while ('R' != array[2][5]){

//asks for the car color
cout << counter << ". User Input: ";
cin >> userInput;
userInput = (upperCase(userInput));
carColor = userInput[0]; // assings the car color from the string first index
carDirection = userInput[1];  //asks for the direction the car will be moving from string index 1
numMoves = userInput[2] - '0'; //asks for the amount of moves the car will make from string index 2 and

if(userInput == "Exit" || userInput[0] == 'X'){
    break;
}

//when reset is typed into the user input then it will reset the board and change the array to have a specific ammount of vehicles placed
//wherever the user chooses
if (userInput == "RESET"){
// this sets all the members in the array to periods
    for (int i = 0; i <6;i++){
        for(int j = 0; j < 6; j++){
            array[i][j] = '.';
        }
    }
    //asks how many vehicles will be displayed on the board
    cout << "How many Vehicles are there? ";
    cin >> howManyVehicles;
      // a for loop for the amount of vehiclies and their placement on the array and in the class
    for( int i=0; i<howManyVehicles; i++) {
        cout << "Please enter Vehicle Color,Direction, X-Position,Y-Position, and Length";
        cin >> userInput;
        userInput = upperCase(userInput);
        vehicle = userInput[0];
        direction = userInput[1];
        xPosition = userInput[2] - '0';
        yPosition = userInput[3] - '0';
        length = userInput[4] - '0';

        if (direction == 'V'){
            for( int i = 0; i <length;i++){
                array[xPosition+i-1][yPosition-1] = vehicle;
            }
        }
        if (direction == 'H'){
            for( int i = 0; i <length;i++){
                array[xPosition-1][yPosition-1+i] = vehicle;
            }
        }

        vehicles[ i] = new Vehicle( vehicle,direction, xPosition, yPosition, length);
    }
counter = 1;
continue;
}
 if (carColor != 'P' && carColor != 'O' && carColor != 'C' && carColor != 'M' &&
         carColor != 'G' && carColor != 'B' && carColor != 'Y' && carColor != 'R'){ //if user input is any of the above then it runs
     cout <<  "User input is not one of the valid color or action items.  Please retry." << endl;
continue;
 }
 if (userInput[1] != 'L' && userInput[1] != 'R' && userInput[1] != 'U' && userInput[1] != 'D'){
     cout <<  "Attempt was made to move a piece in the wrong direction.  Please retry." << endl; //else it will popup with an error
     continue;
     }


 badMove = makeMove(carColor,carDirection,numMoves, array);  //sends user input up to the function above
//infofmrtion that was used to see the text based moves to see if the information input was correct

for (int i = 0; i <6;i++){
    for(int j = 0; j < 6; j++){
        cout <<array[i][j];
    }
    cout << endl;
}


 //if the move is legal then it moves the peices on the visual board.
if(badMove == false){
//moves the peices in the board according to user input R and D direction
if(carDirection == 'R'|| carDirection == 'D'){
    switch(carColor){
            case('R'):redcar->move((40*numMoves),0);break;
            case('G'):greencar->move((40*numMoves),0);break;
            case('B'):bluecar->move(0,(40*numMoves)); break;
            case('Y'):yellowcar->move(0,(40*numMoves)); break;
            case('C'):cyancar->move((40*numMoves),0);break;
            case('M'):magentacar->move(0,(40*numMoves)); break;
            case('O'):orangecar->move(0,(40*numMoves)); break;
            case('P'):pinkcar->move((40*numMoves),0);break;
            default: break;
            }
} //moves pieces in board according to user input U and L direction
if(carDirection == 'U'|| carDirection == 'L'){
    switch(carColor){
            case('R'):redcar->move((-40*numMoves),0);break;
            case('G'):greencar->move((-40*numMoves),0);break;
            case('B'):bluecar->move(0,(-40*numMoves)); break;
            case('Y'):yellowcar->move(0,(-40*numMoves)); break;
            case('C'):cyancar->move((-40*numMoves),0);break;
            case('M'):magentacar->move(0,(-40*numMoves)); break;
            case('O'):orangecar->move(0,(-40*numMoves)); break;
            case('P'):pinkcar->move((-40*numMoves),0);break;
            default: break;
            }
}

counter++;

}
}
if ('R' == array[2][5]){
cout << "You Win!!!"<< endl;
} else {
    cout << "Better luck next time!" << endl;
}
cout << "Exiting game...";


    return 0;
}
