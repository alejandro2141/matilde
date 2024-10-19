#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stack>
//#include "Cell.hpp"

//using namespace std;


// *********************
//    MemNode
// *********************

class Cell ; 
class MemNode
{ 
    public: 
     uint64_t temp ; //To store time when this register was updaed
     int data ;      //data stored
     int match_counter = 0; 
     bool result  ;  // found match 
     Cell*  dest ;   // Where this information was sent
     
    public :
    MemNode();
    MemNode(int tmp, int dta, Cell* dst)    ;
    void showData() ;
};

