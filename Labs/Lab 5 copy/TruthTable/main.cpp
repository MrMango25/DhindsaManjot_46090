/* 
 * File:   main.cpp
 * Author: Manjot Dhindsa
 * Created on June 29, 2015, 12:43 PM\
 * Purpose: To show the truth
 */

//System Libraries
#include <iostream>
using namespace std; //std namespace --> iostream

//User Libraries

//Global constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
  
    //Declare Variables
    bool X,Y;
    
    //Output the heading out the table
    cout<<"The Truth Table."<<endl;
    cout<<"X Y !X !Y X&&Y X||Y X^Y (X^Y)^Y ";
    cout<<"(X^Y)^X !(X&&Y) !X||!Y !(X||Y) !X&&!Y"<<endl;
    
    //Row 1 Output
    X=true;Y=true;
    cout<<(X?'T':'F')<<" ";
    cout<<(Y?'T':'F')<<"  ";
    cout<<(!X?'T':'F')<<"  ";
    cout<<(!Y?'T':'F')<<"   ";
    cout<<(X&&Y?'T':'F')<<"    ";
    cout<<(X||Y?'T':'F')<<"   ";
    cout<<(X^Y?'T':'F')<<"   ";
    cout<<((X^Y)^Y?'T':'F')<<"       ";
    cout<<((X^Y)^X?'T':'F')<<"        ";
    cout<<(!(X&&Y)?'T':'F')<<"        ";
    cout<<(!X||!Y?'T':'F')<<"     ";
    cout<<(!(X||Y)?'T':'F')<<"         ";
    cout<<(!X&&!Y?'T':'F')<<endl;
    
    //Row 2 Output
    X=true;Y=false;
    cout<<(X?'T':'F')<<" ";
    cout<<(Y?'T':'F')<<"  ";
    cout<<(!X?'T':'F')<<"  ";
    cout<<(!Y?'T':'F')<<"   ";
    cout<<(X&&Y?'T':'F')<<"    ";
    cout<<(X||Y?'T':'F')<<"   ";
    cout<<(X^Y?'T':'F')<<"   ";
    cout<<((X^Y)^Y?'T':'F')<<"       ";
    cout<<((X^Y)^X?'T':'F')<<"        ";
    cout<<(!(X&&Y)?'T':'F')<<"        ";
    cout<<(!X||!Y?'T':'F')<<"     ";
    cout<<(!(X||Y)?'T':'F')<<"         ";
    cout<<(!X&&!Y?'T':'F')<<endl;
    
    //Row 3 Output
    X=false;Y=true;
    cout<<(X?'T':'F')<<" ";
    cout<<(Y?'T':'F')<<"  ";
    cout<<(!X?'T':'F')<<"  ";
    cout<<(!Y?'T':'F')<<"   ";
    cout<<(X&&Y?'T':'F')<<"    ";
    cout<<(X||Y?'T':'F')<<"   ";
    cout<<(X^Y?'T':'F')<<"   ";
    cout<<((X^Y)^Y?'T':'F')<<"       ";
    cout<<((X^Y)^X?'T':'F')<<"        ";
    cout<<(!(X&&Y)?'T':'F')<<"        ";
    cout<<(!X||!Y?'T':'F')<<"     ";
    cout<<(!(X||Y)?'T':'F')<<"         ";
    cout<<(!X&&!Y?'T':'F')<<endl;
    
    //Row 4 OutPut
    X=false;Y=false;
    cout<<(X?'T':'F')<<" ";
    cout<<(Y?'T':'F')<<"  ";
    cout<<(!X?'T':'F')<<"  ";
    cout<<(!Y?'T':'F')<<"   ";
    cout<<(X&&Y?'T':'F')<<"    ";
    cout<<(X||Y?'T':'F')<<"   ";
    cout<<(X^Y?'T':'F')<<"   ";
    cout<<((X^Y)^Y?'T':'F')<<"       ";
    cout<<((X^Y)^X?'T':'F')<<"        ";
    cout<<(!(X&&Y)?'T':'F')<<"        ";
    cout<<(!X||!Y?'T':'F')<<"     ";
    cout<<(!(X||Y)?'T':'F')<<"         ";
    cout<<(!X&&!Y?'T':'F')<<endl;
    
    return 0;
}

