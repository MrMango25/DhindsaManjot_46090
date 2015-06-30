/* 
 * File:   main.cpp
 * Author: Manjot Dhindsa
 * Created on June 28, 2015, 3:40 PM
 * Purpose: Homework, Energy Drinks
 */

//System Libraries
#include <iostream> //I/O Library

using namespace std; //Namespace for iostream

//User Libraries

//Global Constants

//Function Prototype 

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare Variables
    float cSurve=12467;          //cSurve= customer survey
    float nEdrnks;               //nEdrnks= Number of energy drinkers
    float nCdrnks;               //nCdrnks= Number of citris drinkers
    float pEdrnks=.14f;          //Percentage of energy drinkers
    float pCdrnks=.64f*pEdrnks;  //Percentage of Citris drinkers
    
    
    //Process of calculating number of drinkers
    nEdrnks=cSurve*pEdrnks;
    nCdrnks=cSurve*pCdrnks;
    cout<<"Number of Energy Drinkers="<<nEdrnks<<endl;
    cout<<"Number of Citris Drinkers="<<nCdrnks<<endl;
    return 0;
}


