// *********************
//    Memory
// *********************
#include "Memory.hpp"

using namespace std;

/*

MemNode Memory::findData(int data)
    {
        std::stack<MemNode> auxStackMem  ;
        //temporal stack for search
        auxStackMem = memSlots      ;   
        while (!auxStackMem.empty()) 
        {
            MemNode auxNode = auxStackMem.top();
            auxStackMem.pop() ;
            if (auxNode.data == data)
            {
                printf("Match en Memoria \n");
                auxNode.result = true ; 
                return auxNode ;
            }
        }
        MemNode voidAuxNode ; 
        return (voidAuxNode)   ;     
    }

int  Memory::saveData(int time, int data, Cell* destination)
    {   
        MemNode auxMemNode(time, data, destination ) ; 
       // printf("Memory Saving %i, %i, %i \n", auxMemNode , auxMemNode , auxMemNode);
        memSlots.push(auxMemNode) ;
        //printMem();
        return 0 ; 
    }

void  Memory::printMem()
    {
         std::stack<MemNode> auxStackMem ;
        auxStackMem = memSlots ;
        //printf(" MEM[%li]",auxStackMem.size()); 
        while (!auxStackMem.empty()) 
        {
            MemNode auxNode =  auxStackMem.top();
            auxStackMem.pop() ;
            auxNode.showData() ; 
            //printf("[T:%li D:%i C:%p]",auxNode.temp ,auxNode.data,auxNode.dest  );  
        }
    }
*/


MemNode* Memory::findData(int data)
    {
        //cout << "Mem("<< memArray.size() << ")" ; 
        for (int i = 0; i < memArray.size(); i++) 
        {
          if (memArray[i].data == data)  
          {
            memArray[i].match_counter = memArray[i].match_counter +1 ; 
            return &memArray[i] ; 
            break ; 
          } 
        }
        return NULL ; 

    }


int  Memory::saveData(int time, int data, Cell* destination)
    {   
        MemNode auxMemNode(time, data, destination ) ; 
       // printf("Memory Saving %i, %i, %i \n", auxMemNode , auxMemNode , auxMemNode);
       // memArray[1] = auxMemNode ;

        memArray.push_back(auxMemNode) ; 
        return 0 ; 
    }

void  Memory::showData()
    {
        cout << "Mem("<< memArray.size() << ")" ; 
        for (int i = 0; i < memArray.size(); i++) 
        {
            memArray[i].showData() ;
        }
        cout << "" ;
    }

