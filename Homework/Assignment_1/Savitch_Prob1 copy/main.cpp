/* 
 * File:   main.cpp
 * Author: Manjot Dhindsa
 * Created on June 28, 2015, 3:30 PM
 * Purpose: Practice Problem From Savitch
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
    int NumOfPs,PsPrPod,TotPeas;
       
    //Output Unknown Here
    cout<<"Press return after entering a number."<<endl;
    cout<<"Enter the number of pods:"<<endl;
    cin>>NumOfPs;
    
    cout<<"Enter the number of peas in a pod:"<<endl;
    cin>>PsPrPod;
    TotPeas=NumOfPs*PsPrPod;
    cout<<"If you have ";
    cout<<NumOfPs;
    cout<<" pea pods"<<endl;
    cout<<"and ";
    cout<<PsPrPod;
    cout<<" peas in each pod, then"<<endl;
    cout<<"you have ";
    cout<<TotPeas;
    cout<<" peas in all the pods."<<endl;
    
    //Exit Stage Right!
    return 0;
}
