#include "Brain.hpp"

using namespace std;

//int id;
//int nneuro ;    

Brain::Brain()
{
  cout << "Brain Constructor\n" ;

  neurons_size_x = sizeof neurons / sizeof neurons[0]; //  rows 
  neurons_size_y = sizeof neurons[0] / sizeof(neurons[0][0]); // cols

} 

void Brain::getInfo()
{
  printf("Brain info Neuron Zize :%i , %i \n",neurons_size_x,neurons_size_y ); 

  cout << "Listing all cells\n" ;
  int x,y ; 

  for(x=0;x<neurons_size_x;x++)
  {
    for(y=0;y<neurons_size_y;y++)
    {
      //printf("Cell ADD:%p ",neurons[x][y] );
      neurons[x][y]->showData() ;
      cout << endl;
    }
    cout << endl; 
  }
  cout << "END Listing\n" ;      
}        

void Brain::createNeurons()
{
  cout << "creating neurons  \n" ;
  int x, y ; 
  int counter = 0 ;

  for(x=0;x<neurons_size_x;x++)
  {
    for(y=0;y<neurons_size_y;y++)
    {
      counter++ ; 
      neurons[x][y] = (Cell*)malloc(sizeof(Cell)); 
      //store his own mem address
      neurons[x][y]->setAddress(neurons[x][y]) ; 
      neurons[x][y]->setId(counter) ;
      neurons[x][y]->setPosition(x,y) ; 
    }
  }

}

void Brain::createNeuralConections()
{
  printf("Brain Create conections \n") ; 
  srand((unsigned) time(NULL));
  int x, y ; 
  for(x=0;x<neurons_size_x;x++)
  {
    for(y=0;y<neurons_size_y;y++)
    { 
      //FOREACH AXON TERMINAL IN THIS CELL 
      int axons_c ; 
      for (axons_c=0;axons_c< neurons[x][y]->axonSize;axons_c++ )
      {
       int new_y = 0 + ( rand() % (neurons_size_y)   );
        // if cell position not exeed array limits we set that addres
        if  (new_y < neurons_size_y+1  && x+1< neurons_size_x )
        {
        neurons[x][y]->setAxonTerminal(neurons[x+1][new_y]) ; 
        }
      }
    }
  }
}

void Brain::processData(int data)
{

cout << "Start to process Data:" << data << " \n" ; 
neurons[0][0]->processData(data) ; 

}









