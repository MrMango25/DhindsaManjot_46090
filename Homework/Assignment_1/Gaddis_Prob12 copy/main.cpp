/* 
 * File:   main.cpp
 * Author: Manjot Dhindsa
 * Created on June 28, 2015, 2:10 PM
 * Purpose: How many acres of land are in square feet
 */

//system libraries
#include <iostream> //File I/O
using namespace std; //std namespace -> iostream

//User Libraries

//Global constants

//Function Prototype

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare Variables Here
    unsigned short oneAcLd = 43560;  //oneAcLd= Amount of square feet in one acre of land
    unsigned int   sqrFt   = 391876; //sqrFt= Square Feet given in problem
    float          Acre;             //When we divide the top two we will get how many acres are in the square feet given
        
    //Process Input Here
    Acre=(static_cast<float>(sqrFt)/oneAcLd);
    
    //Output Unknown Here
    cout<<"the amount of acres is 391876 square feet is ="<<Acre<<endl;
    
    //Exit Stage Right!
    return 0;
}

