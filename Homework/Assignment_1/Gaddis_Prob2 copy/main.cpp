/* 
 * File:   main.cpp
 * Author: Manjot Dhindsa
 * Created on June 28, 2015, 2:00 PM
 * Purpose: Sales Prediction of East Coast sales
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
    float EaCtPer = .58,   //East Cost Percentage of sales from total sales (%)
          CTotSal = 8.6e6, //The total sales that the company had this year (million $)
          EaCtSal;         //Amount of money East Coast made for the company this year (million $)
           
    //Process Input Here
    EaCtSal =(EaCtPer*CTotSal);
    
    //Output Unknown Here
    cout<<"The amount of money the East Coast";
    cout<<" division will generate is="<<EaCtSal<<" million $"<<endl;
    
    //Exit Stage Right!
    return 0;
}

