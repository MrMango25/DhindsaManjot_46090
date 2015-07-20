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
using namespace std; //std namespace -> iostream

//User Libraries

//Global constants

//Function Prototypes
void gameDes();
const int COLS=4;
void blChtP1(char [][COLS],const int);
void prn1Cht(char [][COLS],const int);
void blChtP2(char [][COLS],const int);
void prn2Cht(char [][COLS],const int);
void setSpot(char [][COLS],int,int,char);
bool isHit(char [][COLS],int,int);
char getSpot(char [][COLS],int,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Call the function for the description of the game.
    gameDes();
    
    //Declare variables for battleship chart
    const int SIZE=4;              //Size of the array 0-3
    const int ROW=4;               //Amount of rows
    char      play1Ct[ROW][COLS];  //Rows by Columns Player 1
    char      play2Ct[ROW][COLS];  //Rows by Columns Player 2
    char      totHit1=5;           //=5 ships hits
    char      totHit2=5;           //=5 ships hit
    bool      inProg=true;         //means that the game's still in progress
    
    //Call BattleShip chart function Player 1 
    blChtP1(play1Ct,ROW);
    prn1Cht(play1Ct,ROW);
    cout<<endl;
    
    //Where does player 1 want their ships?
    cout<<"Player 1 will enter the coordinates of their 5 ships"<<endl;
    cout<<"Enter Rows then enter columns"<<endl;
    cout<<endl;
    
    //Loop For player 1 to decide his coordinates
    for(int i=0;i<5;i++){
        int x,y;
        char choice;
        cin>>x;
        cin>>choice;
        switch(choice){
            case 'A':
            case 'a': y=0;break;
            case 'B':
            case 'b': y=1;break;
            case 'C': 
            case 'c': y=2;break;
            case 'D':
            case 'd': y=3;break;
        }
        x--;
        setSpot(play1Ct,x,y,'H');
    }
    prn1Cht(play1Ct,ROW);
    cout<<"These are the positions of your 5 ships."<<endl;
    
    //Call BattleShip Chart Player 2
    blChtP2(play2Ct,ROW);
    prn2Cht(play2Ct,ROW);
    
    //Where does player 2 want their ships?
    cout<<"Player 2 will enter the coordinates of their 5 ships"<<endl;
    cout<<"Enter Rows then enter columns"<<endl;
    cout<<endl;
    
    //Loop For player 2 to decide his coordinates
    for(int i=0;i<5;i++){
        int x,y;
        char choice;
        cin>>x;
        cin>>choice;
        switch(choice){
            case 'A':
            case 'a': y=0;break;
            case 'B':
            case 'b': y=1;break;
            case 'C': 
            case 'c': y=2;break;
            case 'D':
            case 'd': y=3;break;
        }
        x--;
        setSpot(play2Ct,x,y,'H');
    }
    prn2Cht(play2Ct,ROW);
    cout<<"These are the positions of your 5 ships."<<endl;
    
    //Actual game. Players start attacking each other
    do{
        //Player 1 attacks Player 2
        cout<<"Player 1 starts. Choose coordinate to attack."<<endl;
        int x,y;
        char choice;
        cin>>x;
        cin>>choice;
        switch(choice){
            case 'A':
            case 'a': y=0;break;
            case 'B':
            case 'b': y=1;break;
            case 'C': 
            case 'c': y=2;break;
            case 'D':
            case 'd': y=3;break;
        }
        x--;
        //if/else for if the player hits or misses
        if(isHit(play2Ct,x,y)){
            cout<<"Hit."<<endl;
            totHit2--;
            setSpot(play2Ct,x,y,'X');
        }else if(getSpot(play2Ct,x,y)=='X'){
                cout<<"You have already hit this spot."<<endl;
        }else{
            cout<<"Miss."<<endl;
        }
        
        //Player 2 attacks Player 1
        cout<<"Player 2 starts. Choose coordinate to attack."<<endl;
        cin>>x;
        cin>>choice;
        switch(choice){
            case 'A':
            case 'a': y=0;break;
            case 'B':
            case 'b': y=1;break;
            case 'C': 
            case 'c': y=2;break;
            case 'D':
            case 'd': y=3;break;
        }
        x--;
        //if/else for if the player hits or misses
        if(isHit(play1Ct,x,y)){
            cout<<"Hit."<<endl;
            totHit1--;
            setSpot(play1Ct,x,y,'X');
        }else if(getSpot(play1Ct,x,y)=='X'){
            cout<<"You have already hit this spot"<<endl;
        }else{
            cout<<"Miss."<<endl;
        }
        
        if(totHit2==0){
            inProg=false;
            cout<<"Player 1 wins!!"<<endl;
        }else if(totHit1==0){
            inProg=false;
            cout<<"Player 2 wins!!"<<endl;
        }
    }while(inProg);
    
    //Exit Stage Right!
    return 0;
}

void gameDes(){
cout<<"     This game is BattleShip. At the start of this game both\n"
      "players assign coordinates to their ships. Each Player gets\n"
      "fives ships of size 1 by 1. After both players have assigned\n"
      "coordinates for all their ships the players then take turns\n"
      "trying to destroy the enemies ship. Whoever is first to destroy\n"
      "all enemy ships is the winner."<<endl;
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

void setSpot(char temp[][COLS],int x,int y,char c){
    temp[x][y]=c;
}

bool isHit(char chart[][COLS],int x,int y){
    if(chart[x][y]=='H') return true;
    else return false;
}

char getSpot(char chart[][COLS],int x,int y){
    return chart[x][y]; 
}