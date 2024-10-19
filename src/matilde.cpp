#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stack>

#include <chrono>
#include <ctime>
#include <array>

#include "Brain.hpp"


using namespace std;



int main() {
   
    cout << "Starting Matilde  \n" ;
    Brain mainBrain ; 
    mainBrain.createNeurons();
    cout << "CREATE NEURAL CONNECTIONS  \n";
    mainBrain.createNeuralConections() ; 

    //Brain *  mainBrain = new Brain() ;
    
    cout << "****** PROCESS DATA 1234 ***********  \n" ;
    mainBrain.processData(1111) ; 
    mainBrain.processData(2222) ;
    mainBrain.processData(3333) ; 
    mainBrain.processData(3333) ; 
    mainBrain.processData(3333) ; 
    mainBrain.processData(3333) ; 
    mainBrain.processData(3333) ; 
    mainBrain.processData(3333) ; 
    
    mainBrain.getInfo() ; 
    return 0;
}