/* 
 * File:   main.cpp
 * Author: Manjot Dhindsa
 * Created on June 28, 2015, 4.43PM
 * Purpose: Homework, Freefall
 */

//System Libraries
#include <iostream> //I/O Library

using namespace std; //Namespace for iostream

//User Libraries

//Global Constants
const float GRAVITY=3.2174e1f; //Acceleration due to Gravity Earth(ft/sec^2)

//Function Prototype 

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare Variables
    //dist= The distance dropped in (ft) 
    //time=time in (secs))
    float dist, time;
    
    //Prompt the input time
    cout<<"to calculate the distance dropped"<<endl;
    cout<<"Input the time in Seconds"<<endl;
    cout<<"Time should be in floating point format\n";
    cin>>time;
    
    //Calculate the free-fall distance
    dist=GRAVITY*time*time/2;//Correct
    
    //Output the results
    cout<<"the distance traveled=";
    cout<<dist<<"(ft)"<<endl;
   
    //Exit stage right!
    return 0;
}
