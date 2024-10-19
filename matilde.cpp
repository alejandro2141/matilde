#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stack>

#include <chrono>
#include <ctime>
#include <array>

using namespace std;

// *********************
//    MemNode
// *********************
class MemNode
{ 
    public: 
     long int temp ; 
     int data ; 
     int dest ; 
     bool result = false ; 

    MemNode()
    {
    }

    MemNode(int tmp, int dta, int dst)
    {
        temp=tmp;
        data=dta;
        dest=dst;
    }
};
// *********************
//    Memory
// *********************
class Memory
{ 
    public: 
     //MemNode memSlot[10] ;
    stack<MemNode> memSlots;

    MemNode findData(int data)
    {
        stack<MemNode> auxStackMem  ;
        auxStackMem = memSlots      ;   
        while (!auxStackMem.empty()) 
        {
            MemNode auxNode = auxStackMem.top();
            auxStackMem.pop() ;
            if (auxNode.data == data)
            {
              //  printf("Match en Memoria \n");
                auxNode.result = true ; 
                return auxNode ;
            }
        }
        return (MemNode())   ;
        //return NULL ;
        /*
        for (int i = 1; i <= 9; ++i) {
            if (memSlot[i].data == data)
            {
                //return (mem[i].dest) ;
                return true ; 
                i=100 ; 
            }
          
        }
        return false ;
        */    
    }

    int saveData(int time, int data, int destination)
    {   
        MemNode auxMemNode(time, data, destination ) ; 
        memSlots.push(auxMemNode) ;
        return 0 ; 
    }

    void printMem()
    {
        stack<MemNode> auxStackMem ;
        auxStackMem = memSlots ;
        while (!auxStackMem.empty()) 
        {
            MemNode auxNode =  auxStackMem.top();
            auxStackMem.pop() ;
            printf("-->Info  MEM:  Time: %i Data: %i NextCell: %i \n",auxNode.temp ,auxNode.data,auxNode.dest  );  
        }
    }


};
// *********************
//    DEFINITION CELL 
// *********************
class Cell
{ 
    public: 
     int id=0 ;
     int level=0 ;
     Cell* address = NULL ; 
     Cell* motherAddress = NULL ;

     stack<Cell> childStack;
     
     Memory mem ; 
     long int dateBirth;
     
    Cell() 
    { 
        printf("Cell Created \n")  ;
    }

    void setMotherAddress(Cell* mother)
    {
        motherAddress = mother ; 
    }

    void setAddress(Cell* myAdd)
    {
        address = myAdd ; 
    }

    int  reproduce()
    { 
      printf("Cell Reproduce \n")  ;
      Cell *child = new Cell() ;
      child->address= child ;
      child->motherAddress = address ;
      childStack.push(*child) ;
      return 0;
      
      /*
      printf("Cell Reproduce \n")  ;
      Cell child =  Cell() ;
      child.address= &child ;
      child.motherAddress = address ;
      childStack.push(child) ;
      return 0;
      */

    } 

    //Parameterized Constructor 
    int processData(int data)
    {
        printf("Cell %i  Procesando %d \n ", id , data);
        MemNode memfound =  mem.findData(data) ;
         
         if ( memfound.result )
         {
            printf(" data  found in mem  %d  \n", memfound.data);
         } 
         else 
         {
            int nextCell = 0 ;
            printf(" data NOT found in mem \n");
            mem.saveData(static_cast<long int> (time(NULL)) ,data,nextCell) ;
         } 
        return 1 ; 
    }

    void setId(int id)
    {
    }

    void info()
    {
        printf("-->Info CELL address:%d   mother_address:%d \n",  address, motherAddress );
        printf("----- MEM -------------------- \n");
        mem.printMem(); 
        printf("---------------------------------  \n");
        printf("----- Childs -------------------- \n");
        showChilds();
        printf("---------------------------------  \n");
    }
    void showChilds()
    {
        stack<Cell > auxChildStack ;
        auxChildStack = childStack ;
        while (!auxChildStack.empty()) 
        {
            Cell auxCell =   auxChildStack.top();
             auxChildStack.pop() ;
            printf("-->Child: Address  %i  MotherAddress %i  \n",auxCell.address, auxCell.motherAddress  );  
        }
    }

    void showFamily()
    {
        //TODO
        stack<Cell > auxChildStack ;
        auxChildStack = childStack ;
        while (!auxChildStack.empty()) 
        {
            Cell auxCell =   auxChildStack.top();
             auxChildStack.pop() ;
            printf("-->Family Child: Address  %i  MotherAddress %i  \n",auxCell.address, auxCell.motherAddress  );
            auxCell.showFamily() ;  
        }
        
    }
  
}; 


int main() {
    printf("Starting Test \n");

    Cell motherCell = Cell() ;

    motherCell.setMotherAddress(NULL) ; 
    motherCell.setAddress(&motherCell) ; 

    motherCell.reproduce();
    motherCell.reproduce();
    motherCell.reproduce();
    motherCell.reproduce();

    motherCell.childStack.top().reproduce();
    motherCell.childStack.top().reproduce();
     motherCell.childStack.top().childStack.top().reproduce();

    motherCell.info();
//    motherCell.showFamily();

   printf("CHILD TOP address: %d   mother addres: %d    \n", motherCell.childStack.top().address ,  motherCell.childStack.top().motherAddress) ;


    printf("---------- WILL PRINT FAMILY OF %d---------------\n",motherCell.address) ;
    motherCell.showFamily() ;


/*
    Cell *motherCell = new Cell() ;
    motherCell->reproduce();
    motherCell->info();
*/
    
/*    motherCell->setMotherAddress(NULL) ; 
    motherCell->setAddress(motherCell) ; 
    printf("Ending Creation  \n");   
    printf("----> Mother Cell Info:   ");  
    motherCell->info();
     printf("----> Mother Cell reproduce ");  
    motherCell->reproduce();
*/
    //cells->reproduce();
    //printf("REPRODUCE   \n");   
    

/*
    Cell cell[10] ; 
    int sizeCells=sizeof(cell)/sizeof(*cell) ;


    printf("Size Array Cell %d \n", sizeCells );

     for (int y = 0; y < sizeCells ; y++) 
        {
            cell[y].info() ;
        }
*/

/*
    for (int y = 0; y < sizeof(cell) ; y++) 
        {
            cells[y].info() ;
        }
*/
/*
    int net_x = 4;
    int net_y = 3 ;

    Cell redCells[net_x][net_y] ; 

    printf ("Neuronal Network size : %d , %d \n", net_x , net_y  ) ;

    for (int x = 0; x < net_x ; x++) 
    {
        for (int y = 0; y < net_y ; y++) 
        {
            redCells[x][y].setId(x,y);
        }
    }

    redCells[2][2].printInfo() ;
    redCells[2][2].processData(66); 
    redCells[2][2].processData(66); 
    redCells[2][2].processData(99); 
    redCells[2][2].printInfo() ;
*/

    /*
    redCells[0][0].setId(0,0);
    redCells[0][1].setId(0,1);
    redCells[0][2].setId(0,2); 
    
    redCells[1][0].setId(1,0);
    redCells[1][1].setId(1,1);
    redCells[1][2].setId(1,2); 
    
    redCells[2][0].setId(2,0);
    redCells[2][1].setId(2,1);
    redCells[2][2].setId(2,2); 
    

    redCells[0][0].printInfo() ;
    redCells[0][0].processData(66); 
    redCells[0][0].processData(99); 
    redCells[0][0].printInfo() ;

    for (int i = 0; i < 5; i++) {
    cout << i << "\n";
    }
    */


    /*
    redCells[0].setId(0); 
    redCells[1].setId(1); 
    redCells[2].setId(2); 
    
    redCells[0].printInfo() ;
    redCells[0].processData(66); 
    redCells[0].printInfo() ;
    redCells[0].processData(56); 
    redCells[0].printInfo() ;
   */

    return 0;
}