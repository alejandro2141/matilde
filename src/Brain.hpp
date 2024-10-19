#include <stdio.h>
#include <iostream>    
#include <array>
#include <time.h>

#include "Cell.hpp"

class Brain
{

    public: 
        int id;
        int neurons_size_x ;
        int neurons_size_y ;
        
    private:   
        Cell* neurons[3][3] ;
       // Cell* neurons ;
        
    public:
        Brain();
        void getInfo() ;
        void createNeurons();
        void createNeuralConections() ;

        void processData(int) ; 

};

