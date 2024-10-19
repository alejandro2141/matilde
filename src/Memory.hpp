#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stack>
#include <vector>
#include "MemNode.hpp"
//#include "Cell.cpp"

using namespace std;

class Memory
{
    public: 
     
     vector<MemNode> memArray{};
    
    // int* dynamicArray = new int[n];
    // MemNode* memArray = new MemNode[memSize];
    // std::vector<int> dynamicArray{};

    int saveData(int time, int data, Cell* destination);
    MemNode* findData(int data) ;
    void showData();

/* 
    public: 
    std::stack<MemNode> memSlots;

    public:
    MemNode findData(int data) ;
    int saveData(int time, int data, Cell* destination);
    void printMem();
*/

};
