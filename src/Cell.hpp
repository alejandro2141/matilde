#include <stdio.h>
#include <iostream>
#include <chrono>
#include "Memory.hpp"

class Cell
{
    public: 
     int id;
     Cell* address = 0 ;  
     static const int axonSize = 3;
     Cell* axonTerminals[axonSize];
     Memory memory ; 

    /*
     Cell *axonTerminals = new Cell[5]; 
     Cell *dendritasTerminals = new Cell[5];  
    */

     int pos_x ;
     int pos_y ; 
     

    public:
     void showData() ;  
     Cell(); 
     void setId(int ident); 
     void setAddress(Cell* addr) ; 
     void setPosition(int x,int y) ; 
     void setAxonTerminal(Cell* addr) ;
     void processData(int);
   
};

