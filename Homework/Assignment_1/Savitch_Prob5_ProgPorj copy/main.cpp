/* 
 * File:   main.cpp
 * Author: Manjot Dhindsa
 * Created on June 28, 2015, 4:48 PM
 * Purpose: Homework
 */

//system libraries
#include <iostream> //File I/O
#include <iomanip>
using namespace std; //std namespace -> iostream

//User Libraries

//Global constants

//Function Prototype

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare Variables Here
    char N;
    
    //Output Unknown Here
    cout<<"Input any letter here"<<endl;
    cin>>N;
    cout<<setw(6)<<N<<N<<N<<endl;
    cout<<setw(5)<<N<<setw(4)<<N<<endl;
    cout<<setw(4)<<N<<endl;
    cout<<setw(4)<<N<<endl;
    cout<<setw(4)<<N<<endl;
    cout<<setw(4)<<N<<endl;
    cout<<setw(4)<<N<<endl;
    cout<<setw(5)<<N<<setw(4)<<N<<endl;
    cout<<setw(6)<<N<<N<<N<<endl;
   
    //Exit Stage Right!
    return 0;
}
