/* 
 * File:   main.cpp
 * Author: Manjot Dhindsa
 * Created on June 30, 2015, 12:23 PM
 * Purpose: math tutor program
 */

//System Libraries
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

//User Libraries

//Global constants

//FunctionPrototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //set the random seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    unsigned short op1,op2,result;
    bool doAgain;
    
    //Loop based upon continuing to play with the math tutor
    do{
        //Determine op1/op2
        op1=rand()%900+100;//[100-999]
        op2=rand()%900+100;//[100-999]
        
        //Display the problem
        cout<<setw(6)<<op1<<endl;
        cout<<" + "<<op2<<endl;
        cout<<"------"<<endl;
        
        //Input the value for the sum
        cin>>result;
        
        //If coorect output congratulations else try again?
        if(result==op1+op2){
            cout<<"Congratulations"<<endl;
        }else{
            cout<<"Wrong Answer"<<endl;
        }
        
        //Prompt if they would like to continue
        cout<<"Would you like to continue y/n"<<endl;
        char response;
        cin>>response;
        if(response=='y')doAgain=true;
        else doAgain=false;
    }while(doAgain);
    
    //Exit stage right!
    return 0;
}