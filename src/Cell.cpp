#include "Cell.hpp"

using namespace std;

//int id;   
//int memAddress ;

void Cell::showData()
{
  printf("Cell id:%i Pos(%i,%i) ad:%p  Axons:%i", id , pos_x, pos_y , address, axonSize);

  cout << "[" ; 
  int x;
    for(x=0;x<axonSize ;x++)
    {
      printf("%p,",axonTerminals[x] );
    }
  cout << "] " ; 
  //cout << "Show Memory:[" ; 
   memory.showData() ;
}        

Cell::Cell()
{
  address = 0 ; 
  //sizeof(arr)/sizeof(arr[0]);
  //axonTerminals[3] =  ;
  //printf("Cell Constructor id: %i \n", id ); 
} 

void Cell::setId(int ident)
{
  id = ident ; 
}

void Cell::setAddress(Cell* addr)
{
  address = addr ; 
}

void Cell::setPosition(int x,int y) 
{
  pos_x = x ; 
  pos_y = y ; 
}

void Cell::setAxonTerminal(Cell* addr)
{
   int x;
   bool isFull = true ; 
    for(x=0;x<axonSize ;x++)
    {
       if (axonTerminals[x]==NULL) 
       {
        axonTerminals[x]=addr ;
        isFull = false ;
        break;
       }



    }

    //If all axons are full we overwrite any
    if (isFull==true)
    {
      //
     int axonPosRand = 0 + ( rand() % (axonSize) ) ;
     axonTerminals[axonPosRand]=addr ;
    }

}


 void Cell::processData(int data)
 {
  //cout << "Cell ID:"<< id << " Processing Data:"<< data << "  \n" ;  
 //1- Search Data in Memory 
    MemNode* mem;  
    mem = memory.findData(data) ; 
    if ( mem != NULL)
    {
      //printf("FOUND!!! MEM %li %i %p", mem->temp , mem->data, mem->dest );
      Cell* auxCell = mem->dest ; 
      if (auxCell != NULL )
        {auxCell->processData(data) ;}

      /*
      cout << data  << " FOUND  !!!  \n" ; 
      Cell* auxCell = mem->dest  ;
      auxCell->processData(data) ; 
      */

      // 1.1 should return a message


    }
    else 
    {
      //cout << data  << " NOT FOUND  !!!  \n" ; 
      //2- Not found in Memory so save in memory and sento to random axon
      //2.1 Choose a random axon to send it because is new
      int axonPosRand = 0 + ( rand() % (axonSize) ) ;
      //2.2  Save in Memory this new data

      // Get the current time from the system clock
       using namespace chrono;
       uint64_t millisec = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
      //********************************************

      memory.saveData(millisec, data, axonTerminals[axonPosRand]) ;
      if(axonTerminals[axonPosRand] != NULL)
      {
      axonTerminals[axonPosRand]->processData(data) ; 
      }

    }

 


 }

