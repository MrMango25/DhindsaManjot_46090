/* 
 * File:   main.cpp
 * Author: Manjot Dhindsa
 * Created on July 15, 2015, 9:02 PM
 * Purpose: BattleShip Game
 */

//System Libraries
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std; //std namespace -> iostream

//User Libraries
#include "var.h"

//Global constants

//Function Prototypes
const int COLS=4;
void blChtP1(char [][COLS],const int);
void prn1Cht(char [][COLS],const int);
void blChtP2(char [][COLS],const int);
void prn2Cht(char [][COLS],const int);
void clrScrn();
void setSpot(char [][COLS],int,int,char);
bool isHit(char [][COLS],int,int);
char getSpot(char [][COLS],int,int);
void markSrt(vector<string> &);
void swapMin(vector<string> &,int);
void swap(vector<string> &,int,int);
void prnVect(vector<string> &);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Bring in file for the description of the game.
    ifstream infile("BattleshipRules.txt");
    string   rules;
    while(!infile.eof()){
        infile>>rules;
        cout<<rules<<" ";
    }
    cout<<endl;
    infile.close();
    
    //Declare variables for battleship chart
    vector<string> play1,play2;     //Vector string to hold players coordinates
    const int ROW=4;                //Amount of rows
    char      play1Ct[ROW][COLS];   //Rows by Columns Player 1
    char      play2Ct[ROW][COLS];   //Rows by Columns Player 2
    char      blnk1Ct[ROW][COLS];   //Blank Chart Player 1
    char      blnk2Ct[ROW][COLS];   //Blank Chart Player 2
    char      **shipPos;            //Player 1 position
    char      **shiPos2;            //Player 2 position
    bool      inProg=true;          //Means that the game is still in progress
    string    name1,                //Player 1 name
              name2;                //Player 2 name
    int       ships;                //Amount of ships
    var c;
    
    //Enter player 1 name
    cout<<"What is player 1 name? ";
    getline(cin,name1);
    
    //Enter player 2 name
    cout<<"What is player 2 name? ";
    getline(cin,name2);
    
    //Call BattleShip chart function Player 1 
    blChtP1(play1Ct,ROW);
    prn1Cht(play1Ct,ROW);
    blChtP1(blnk1Ct,ROW);
    cout<<endl;
    
    //Where does player 1 want their ships?
    cout<<"How many ships do you want to place?\n"
          "The amount of ships you chose player 2 will also have.\n";
    do{
        cin>>ships;
        if(ships<1){
            cout<<"Please enter a number of ships between 1 and 5: ";
        }else if(ships>5){
            cout<<"Please enter a number of ships between 1 and 5: ";
        }
    }while(ships<1||ships>5);
    
    //Assign 2d dynamic array to address. ex if ships=5 assigned to 5 addresses
    shipPos=new char *[ships];
    //Each address will now be able to hold 2 char data 
    for(int i=0;i<ships;i++){
        shipPos[i]=new char[2];
    }
    cout<<endl;
    cout<<name1<<" will enter the coordinates of their "<<ships<<" ships"<<endl;
    cout<<"Enter Rows then enter columns. ex:(1A or 1a)"<<endl;
    cout<<endl;
    
    //Set decrementing totHit1 and totHit2 equal to amount of ships
    c.totHit1=ships;
    c.totHit2=ships;
    
    //Loop For player 1 to decide his coordinates
    for(int i=0;i<ships;i++){
        bool def=true;
        int x,y;
        char choice;
        cin>>x;
        while(def){
            cin>>choice;
            switch(choice){
                case 'A':
                case 'a': y=0;
                          def=false;break;
                case 'B':
                case 'b': y=1;
                          def=false;break;
                case 'C': 
                case 'c': y=2;
                          def=false;break;
                case 'D':
                case 'd': y=3;
                          def=false;break;
                default: cout<<"Invalid choice. Please enter a different letter: ";
            }
        }
        x--;
        //Stores each coordinate into the string then vector
        string s="";
        s+=static_cast<char>(x+49);
        s+=choice;
        play1.push_back(s);
        shipPos[i][0]=x+49;
        shipPos[i][1]=y+65;
        setSpot(play1Ct,x,y,'H');
    }
    prn1Cht(play1Ct,ROW);
    cout<<"These are the positions of your "<<ships<<" ships."<<endl;
    
    //Call BattleShip Chart Player 2
    blChtP2(play2Ct,ROW);
    prn2Cht(play2Ct,ROW);
    blChtP2(blnk2Ct,ROW);
    
    shiPos2=new char *[ships];
    for(int i=0;i<ships;i++){
        shiPos2[i]=new char[2];
    }
    //Where does player 2 want their ships?
    cout<<name2<<" will enter the coordinates of their "<<ships<<" ships"<<endl;
    cout<<"Enter Rows then enter columns. ex:(1A or 1a)"<<endl;
    cout<<endl;
    
    //Loop For player 2 to decide his coordinates
    int i=0;
    while(i<ships){
        bool def=true;
        int x,y;
        char choice;
        cin>>x;
        while(def){
            cin>>choice;
            switch(choice){
                case 'A':
                case 'a': y=0;
                          def=false;break;
                case 'B':
                case 'b': y=1;
                          def=false;break;
                case 'C': 
                case 'c': y=2;
                          def=false;break;
                case 'D':
                case 'd': y=3;
                          def=false;break;
                default: cout<<"Invalid choice. Please enter a different letter: ";
            }
        }
        x--;
        //Stores each coordinate into the string then vector
        string s="";
        s+=static_cast<char>(x+49);
        s+=choice;
        play2.push_back(s);
        shiPos2[i][0]=x+49;
        shiPos2[i][1]=y+65;
        setSpot(play2Ct,x,y,'H');
        i++;
    }
    prn2Cht(play2Ct,ROW);
    cout<<"These are the positions of your "<<ships<<" ships."<<endl;
    clrScrn();
    
    //Actual game. Players start attacking each other
    do{
        //Declare Variables in scope
        bool potato=true;
        bool def=true;
        char choice;
        int  x,y;
        
        //Player 1 attacks Player 2
        cout<<name1<<" starts. Choose coordinate to attack."<<endl;
        cin>>x;
        while(def){
            cin>>choice;
            switch(choice){
                case 'A':
                case 'a': y=0;
                          def=false;break;
                case 'B':
                case 'b': y=1;
                          def=false;break;
                case 'C': 
                case 'c': y=2;
                          def=false;break;
                case 'D':
                case 'd': y=3;
                          def=false;break;
                default: cout<<"Invalid choice. Please enter a different letter: ";
            }
        }
        x--;
        //if/else for if the player hits or misses
        if(isHit(play2Ct,x,y)){
            //If they Hit the target the blank chart prints with an X
            cout<<"Hit."<<endl;
            c.totHit2--;
            setSpot(play2Ct,x,y,'X');
            setSpot(blnk2Ct,x,y,'X');
            prn1Cht(blnk2Ct,ROW);
        }else if(getSpot(play2Ct,x,y)=='X'){
            cout<<"You have already hit this spot"<<endl;
        }else if(getSpot(play2Ct,x,y)=='_'){
            //If they Miss the target the blank chart prints with an M
            setSpot(play2Ct,x,y,'M');
            setSpot(blnk2Ct,x,y,'M');
            prn1Cht(blnk2Ct,ROW);
            cout<<"Miss."<<endl;
        }
        
        //Player 2 attacks Player 1
        cout<<name2<<" starts. Choose coordinate to attack."<<endl;
        cin>>x;
        while(potato){
            cin>>choice;
            switch(choice){
                case 'A':
                case 'a': y=0;
                          potato=false;break;
                case 'B':
                case 'b': y=1;
                          potato=false;break;
                case 'C': 
                case 'c': y=2;
                          potato=false;break;
                case 'D':
                case 'd': y=3;
                          potato=false;break;
                default: cout<<"Invalid choice. Please enter a different letter: ";
            }
        }
        x--;
        //if/else for if the player hits or misses
        if(isHit(play1Ct,x,y)){
            //If they Hit the target the blank chart prints with an X
            cout<<"Hit."<<endl;
            c.totHit1--;
            setSpot(play1Ct,x,y,'X');
            setSpot(blnk1Ct,x,y,'X');
            prn2Cht(blnk1Ct,ROW);
        }else if(getSpot(play1Ct,x,y)=='X'){
            cout<<"You have already hit this spot"<<endl;
        }else if(getSpot(play1Ct,x,y)=='_'){
            //If they Miss the target the blank chart prints with an M
            setSpot(play1Ct,x,y,'M');
            setSpot(blnk1Ct,x,y,'M');
            prn2Cht(blnk1Ct,ROW);
            cout<<"Miss."<<endl;
        }
        
        if(c.totHit2==0){
            inProg=false;
            cout<<name1<<" wins!!"<<endl;
        }else if(c.totHit1==0){
            inProg=false;
            cout<<name2<<" wins!!"<<endl;
        }
    }while(inProg);
    
    //Sort positions of ships and call mark sort
    markSrt(play1);
    markSrt(play2);
    cout<<"These were "<<name1<<" coordinates"<<endl;
    prnVect(play1);
    cout<<endl;
    cout<<"These were "<<name2<<" coordinates"<<endl;
    prnVect(play2);
            
    //Delete the vector dynamic arrays
    for(int i=0;i<ships;i++){
        delete[] shipPos[i];
    }
    delete[] shipPos;
    
    //Exit Stage Right!
    return 0;
}

/************************************************************
 ************* Makes Battleship Chart for P1 ****************
 ************************************************************
 * Purpose: Makes 4 by 4 chart
 */
void blChtP1(char play1Ct[][COLS],const int ROW){
    //Loop To Find Chart
    for(int i=0;i<ROW;i++){        
        for(int j=0;j<COLS;j++){
            play1Ct[i][j]='_';
        }
        cout<<endl;
    }
}

/************************************************************
 **************** Prints Battleship Chart P1 ****************
 ************************************************************
 * Purpose: Prints out already made chart
 */
void prn1Cht(char play1Ct[][COLS],const int ROW){
    cout<<"   ";
    for(int i=1;i<=1;i++){
        cout<<"   "<<"A"<<"    "<<"B"<<"    "<<"C"<<"    "<<"D";
    }cout<<endl;
    cout<<"     ******************"<<endl;
    for(int i=0;i<ROW;i++){
        cout<<i+1<<":";
        for(int j=0;j<COLS;j++){
            cout<<setw(5)<<play1Ct[i][j];
        }
        cout<<endl;
    }
}

/************************************************************
 ************* Makes Battleship Chart for P2 ****************
 ************************************************************
 * Purpose: Makes 4 by 4 chart
 */
void blChtP2(char play2Ct[][COLS],const int ROW){
    //Loop To Find Chart
    for(int i=0;i<ROW;i++){        
        for(int j=0;j<COLS;j++){
            play2Ct[i][j]='_';
        }
        cout<<endl;
    }
}

/************************************************************
 *************** Prints Battleship Chart P2 *****************
 ************************************************************
 * Purpose: Prints out already made chart
 */
void prn2Cht(char play2Ct[][COLS],const int ROW){
    cout<<"   ";
    for(int i=1;i<=1;i++){
        cout<<"   "<<"A"<<"    "<<"B"<<"    "<<"C"<<"    "<<"D";
    }cout<<endl;
    cout<<"     ******************"<<endl;
    for(int i=0;i<ROW;i++){
        cout<<i+1<<":";
        for(int j=0;j<COLS;j++){
            cout<<setw(5)<<play2Ct[i][j];
        }
        cout<<endl;
    }
}

/************************************************************
 ********************* clear screen *************************
 ************************************************************
 * Purpose: ends fifty lines after coordinates are chosen 
 */
void clrScrn(){
    for(int i=0;i<50;i++){
        cout<<endl;
    }
}

/************************************************************
 ************************ setSpot ***************************
 ************************************************************
 * Purpose: changes spot on chart to H or X
 */
void setSpot(char temp[][COLS],int x,int y,char c){
    temp[x][y]=c;
}

/************************************************************
 ************************* isHit ****************************
 ************************************************************
 * Purpose: checks to see if coordinate = H on chart
 */
bool isHit(char chart[][COLS],int x,int y=0){
    //Using Ternary Operator
    return (chart[x][y]=='H'?true:false);
}

/************************************************************
 ************************* getSpot **************************
 ************************************************************
 * Purpose: makes it so you cant attack same spot twice
 */
char getSpot(char chart[][COLS],int x,int y){
    return chart[x][y]; 
}

/**************************************************
 *                Mark Sort                       *
 **************************************************
 * Purpose:  
 */
void markSrt(vector<string> &a){
    //Loop and sort every position
    for(int pos=0;pos<a.size()-1;pos++){
        swapMin(a,pos);
    }
}

/**************************************************
 *                   SwapMin                      *
 **************************************************
 * Purpose:  
 */
void swapMin(vector<string> &a,int pos){
    //Loop through the list starting at possible+1
    for(int i=pos+1;i<a.size();i++){
        //Place smallest value at the position possible
        if(a[pos].compare(a[i])>0)swap(a,pos,i);
    }
}

/**************************************************
 *                     Swap                       *
 **************************************************
 * Purpose:  
 */
void swap(vector<string> &a,int pos, int pos2){
    //Perform the logical in-place swap
    string temp=a[pos];
    a[pos]=a[pos2];
    a[pos2]=temp;
}

void prnVect(vector<string> &v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}
