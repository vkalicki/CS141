/* steiner.cpp
 *  Graphics demo program for getting started with QtCreator for program 6, Steiner Trees.
 *
 * Author: Veronica Kalicki
 * Date: 12/04/17
 * Class: CS 141, Fall 2017
 * System: QtCreator with Stanford graphics library, on iMac, OS Sierra
 *
 */

#include <iostream>
#include "gobjects.h"  // for all graphics objects
#include "gevents.h"   // for mouse events
#include <fstream>        // For file input
#include <cmath>
#include <ctime>
using namespace std;

// Global constants
const int PointRadius = 7;

// Create a graphics window, which will be used to draw graphical shapes.
// This can be a global variable, but you may not have any other global variables.
GWindow graphicsWindow;
//------------------------------------------------------------------------------------------
//class that creates my circles
class MyPoint{

public:
    //my constructor
    MyPoint (int x, int y , string color = "Black"){
        setX(x); setY(y); setRadius(radius); setColor(color);
    }
    //my set functions that assign variable to private variables
    void setX(int x){this->xCord = x;}
    void setY(int y){this->yCord = y;}
    void setRadius(int radius){this->radius = radius;}
    void setColor(string  color){this->circleColor = color;}
    //my retreive functions
    int getX(){return xCord;}
    int getY(){return yCord;}
    //my function that creates a circle
    void MakePoint(){
        // Center the oval to be drawn on the x,y location. PointRadius is a global constant.
        GOval *pTheOval = new GOval( xCord-PointRadius, yCord-PointRadius, PointRadius*2, PointRadius*2);
        pTheOval->setFilled( true);
        pTheOval->setColor( circleColor);
        graphicsWindow.add( pTheOval);
    }
    //private information that ccan only be accessed using get functions
private:
    int xCord, yCord;
    int radius = PointRadius;
    string circleColor;
    bool visability;
    GOval * theCircle;
};

//------------------------------------------------------------------------------------------
//button class that creates button and labels
class MyButton{

public:
    //constructor
    MyButton (int theX, int theY, int theWidth,int theHeight, string theColor,string textWords){
        setX(theX); setY(theY); setWidth(theWidth); setHeight(theHeight); setColor(theColor); setText(textWords);
    }
    //my set functions that assign variable to private variables
    void setX(int x){this->xCord = x;}
    void setY(int y){this->yCord = y;}
    void setWidth(int width){this->Width = width;}
    void setHeight(int height){this->Height = height;}
    void setColor(string color){this->labelColor = color;}
    void setText(string text){this->textOnButton = text;}
    //function that creates button
    void MakeButton(){
        GRect *button = new GRect(xCord, yCord, Width, Height);
        button->setColor( labelColor );
        button->setFilled( true);
        graphicsWindow.add( button);

        // Create the Exit button text that appears on top of the rectangle
        GLabel *buttonLabel = new GLabel();
        buttonLabel->setText(textOnButton);
        // Find size of text, to determine placement relative to enclosing rectangle
        int xOffset = (Width  - buttonLabel->getBounds().getWidth()) / 2;
        int yOffset = (Height - buttonLabel->getBounds().getHeight()) + 5;
        buttonLabel->setLocation( xCord + xOffset, yCord + yOffset);
        graphicsWindow.add( buttonLabel);
    }
    GRect * button;
    //private variable information
private:
    int xCord, yCord, Width, Height;
    string labelColor, textOnButton;
};

//------------------------------------------------------------------------------------------
// Read in the sets of points information from the data file
// You muse make the pointsArray Vector a reference parameter so that read-in values are
// reflected back to the caller.
void readInputFile(  int &idealScore, MyPoint *circlesArray[], int &numOfPoints)
{
    ifstream inputFileStream;  // declare the input file stream

    // Open input file and verify.
    // You must first:
    //    1. Outside of QtCreator go into your project's resources folder, copy readme.txt into data.txt
    //    2. Edit data.txt to have the datafile information as shown on the assignment page
    //    3. Now WITHIN QtCreator right-click on the "res" folder (under "Other files") and
    //       choose "add new" and add the new data.txt file so it shows up in your environment.
    inputFileStream.open("data.txt");
    if( !inputFileStream.is_open()) {
        cout << "Could not find input file data.txt.  Exiting..." << endl;
        exit( -1);
    }

    // Read sets of data from input file.  Each read operation reads the next set of data.
    // The first line in the input file indicates which set to use.
    int whichSetToUse;
    inputFileStream >> whichSetToUse;

    int howManyPoints;    // How many points are in the set of points
    int x, y;             // Store individual point x,y values from input file
    // Reserve some reasonable number of total points for the vector, so that

    // Read in and discard some number of sets of points before we get the real set we will be using
    for( int i = 0; i < whichSetToUse-1; i++) {
        inputFileStream >> howManyPoints >> idealScore;
        for( int j = 0; j < howManyPoints; j++) {
            inputFileStream >> x >> y;    // Read in the points
        }
    }

    inputFileStream >> howManyPoints >> idealScore;
    numOfPoints = howManyPoints; //sends back how many circles there are

    // Read in and store the points information
    for( int i = 0; i < howManyPoints; i++) {
        inputFileStream >> x >> y;    // Read in the points
        // This is where you should take the points information and create points on the screen.
        // For now we will just print out the points information.
        circlesArray[i] = new MyPoint(x,y); //sends information to lass
        circlesArray[i]->MakePoint(); //makes the circle on board
    }
}//end readInputFile()
//------------------------------------------------------------------------------------------
//distance Formula that finds score and closeCircle
int distanceFormula(int x1, int y1, int x2, int y2){
    float theX = pow((x2-x1),2);
    float theY = pow((y2 - y1),2);
    return sqrt(theX + theY);
}
//------------------------------------------------------------------------------------------
//close cirlce finds the circle that is closest to the end of the line and appends it to it
void closeCircle(int &theX,int &theY, MyPoint *circle[], int numCircles){
    int smallestX = circle[0]->getX();     int smallestY = circle[0]->getY();
    int length = distanceFormula(smallestX,smallestY,theX,theY);
    int smallestLenght = 0;
    for(int i = 0; i < numCircles; i++){
        smallestLenght = distanceFormula(theX,theY,circle[i]->getX(), circle[i]->getY());
        if(smallestLenght < length){ //if there exists a smaller distance then it assigns the x and y to the smallest x and smallest y to append to point
            smallestX = circle[i]->getX();
            smallestY = circle[i]->getY();
        }
    }
    //returns the smallest x and y distance
    theX = smallestX;
    theY = smallestY;
}
//------------------------------------------------------------------------------------------
int main()
{
    graphicsWindow.setCanvasSize( 400, 400);   // Set the size
    graphicsWindow.setWindowTitle("  Vkalic2  QtCreator Program 6");

    MyPoint *circleArray[ 15];  //my array of points and some extra for when we make them
    Vector <GLine*> listOfLines; //my list of lines that get stored in a vector so i they dont disapear


    // ... Create something similar to store all GLine * lines
    int idealScore = 0;             // Precomputed ideal score for each puzzle
    int numberOfPoints = 0; //number of circles total
    int totalScore = 0; // total score of lines distance

    // Get the set of data to use from the input file
    readInputFile( idealScore, circleArray,numberOfPoints);
    int acceptRange = (idealScore * 1.05); //sets the range that is close enough to ideal


    // Create the Control and message components.
    // First create the messages label at the top of the window
    GLabel *messagesLabel = new GLabel();
    messagesLabel->setText("Find the minimal spanning tree, using additional points.");
    messagesLabel->setLocation( 30,20);
    graphicsWindow.add( messagesLabel);  // As with all components, after creating them you must also
    // add them to the graphics window, otherwise they will
    // exist but won't show up.


    //sends information up to class and makes each button appear on the screen
    MyButton *exit = new MyButton( 250,350, 50,30, "RED", "Exit");
    exit->MakeButton();
    MyButton *addPoints = new MyButton(10,350, 70, 30, "GREEN", "AddPoints");
    addPoints->MakeButton();
    MyButton *drawLines = new MyButton (90,350,70, 30,"LIGHTGRAY","DrawLines");
    drawLines->MakeButton();

    // Set values to use for keeping track of program modes
    const int Default = 0;
    const int DrawPoints = 1;
    const int DrawLines = 2;
    int programMode = Default;  // Modes are Default, DrawPoints, DrawLines. Start in Default mode
    // Change to the other modes when those buttons are pressed.
    bool buttonWasPressed = false;    // Set to false when a button is pressed.  Used to avoid drawing on buttons
    // immediately when they are pressed.

    int mouseX = -1;                    // Will store mouse position
    int mouseY = -1;
    char howFar[ 81];
    char message[ 81];                  // Used to construct message to be displayed at top of window
    GLine *pLine = new GLine(0,0,0,0);  // Line to be drawn on the screen.  It starts out as a single unseen point.
    pLine->setLineWidth(2);
    graphicsWindow.add(pLine);

    //creates bottom right lenght sign
    GLabel *bottomRight = new GLabel();
    bottomRight->setText("Length:");
    bottomRight->setLocation( 310,370);
    graphicsWindow.add( bottomRight);
    //makes the bottom right score counter
    GLabel *bottomRightNumber = new GLabel();
    bottomRightNumber->setLabel("0");
    bottomRightNumber->setLocation( 327,390);
    graphicsWindow.add( bottomRightNumber);

    GMouseEvent e;      // Stores the mouse event each time through the event loop
    int counter = 0;    // Used to display debugging information, to help understand how the event loop works.

    // While this will be in the event loop, depending on how users interact with your application, for now this
    // just illustrates how the program can draw a point at some x,y spot, with a given radius and color.
    //myInfo
cout << "Name: Veronica Kalicki" << endl;
cout << "Program: #6, Steiner Trees" << endl;
cout <<  "TA:  Moumita Samanta, Tues 9am" << endl;
cout << "Dec 4, 2017" << endl;


    // Main event loop.  Most of your code will go in here, to handle the different mouse events.
    while (true) {
        // Wait for a mouse event, then get the x,y coordinates
        e = waitForEvent(MOUSE_EVENT);
        // Get the current mouse x,y location
        mouseX = e.getX();
        mouseY = e.getY();



        //  -------- Perform actions for different kinds of mouse events --------
        if (e.getEventType() == MOUSE_PRESSED) {
            sprintf( message,"Mouse pressed at %d,%d", mouseX, mouseY);  // print into a string
            messagesLabel->setLabel(message);

            // See if Exit button was clicked by seeing if mouse press location is inside the rectangle
            if( exit->button->contains( mouseX, mouseY) ) {
                messagesLabel->setLabel("Exiting...");
                break;
            }
            //see if addPoints was clicked
            else if( addPoints->button->contains( mouseX, mouseY) ) {
                messagesLabel->setLabel("Add Points Button Pressed");
                programMode = DrawPoints;
                buttonWasPressed = true;
            //checks to see if drawLines was clicked
            } else if( drawLines->button->contains( mouseX, mouseY) ) {
                messagesLabel->setLabel("Draw Lines Button Pressed");
                programMode = DrawLines;
                buttonWasPressed = true;
            } else {
                //cout << "Setting line start and end points to " << mouseX << "," << mouseY << endl;
                messagesLabel->setLabel(message);
                // Set the start point of the already existing line
                closeCircle(mouseX,mouseY,circleArray,numberOfPoints);
                pLine->setStartPoint( mouseX, mouseY);
            }
        }
        else if( e.getEventType() == MOUSE_RELEASED) {
            //prevents double clicking on buttons
            if(buttonWasPressed) {
                buttonWasPressed = false;
                continue;
            }
            //allows me to draw points on the screen
            if (programMode == DrawPoints){
                circleArray[numberOfPoints] = new MyPoint( mouseX,mouseY, "Blue");
                circleArray[numberOfPoints]->MakePoint();
                numberOfPoints= numberOfPoints + 1;
            //allows me to draw lines on the screen
            } else if (programMode == DrawLines){
                closeCircle(mouseX,mouseY,circleArray,numberOfPoints);
                pLine->setEndPoint(mouseX, mouseY); // puts the end of line on a circle that is nearby
                GLine* lineMember = new GLine(pLine->getStartPoint().getX() , pLine->getStartPoint().getY(), mouseX,mouseY);  // Line to be drawn on the screen.  It starts out as a single unseen point.
                graphicsWindow.add(lineMember);
                listOfLines.push_back(lineMember);

                // use to calculate and display the score
                totalScore += distanceFormula(pLine->getStartPoint().getX() , pLine->getStartPoint().getY(), pLine->getEndPoint().getX(),pLine->getEndPoint().getY());
                sprintf( howFar,"%d", totalScore);
                bottomRightNumber->setLabel(howFar);
                if (acceptRange  >= totalScore){
                   sprintf( message,"Great %d is less than %d", totalScore, idealScore);  // print into a string
                   messagesLabel->setLabel(message);
                 }else if (acceptRange < totalScore){
                    sprintf( message,"sorry %d is greater than %d", totalScore, idealScore);  // print into a string
                    messagesLabel->setLabel(message);
                }
            }
        }

        else if(e.getEventType() == MOUSE_DRAGGED) {
            // The previous MOUSE_PRESSED event created the line, though with beginning and ending points being the same.
            // Now set the end point to be at the new mouse destination.  Don't create the new line here, since we don't
            // want to do that until the MOUSE_RELEASED event.
            pLine->setEndPoint(mouseX, mouseY);
        }//else if( e.getEventType()...

    }//end while( true)

    // Close the windows, first the graphics window
    graphicsWindow.requestFocus();
    graphicsWindow.close();
    exitGraphics();
    return 0;
}
