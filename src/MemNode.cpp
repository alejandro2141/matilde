#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stack>

#include "MemNode.hpp"

//using namespace std;

// *********************
//    MemNode
// *********************


MemNode::MemNode()
    { 
       result = false ;    
    } 
MemNode::MemNode(int tmp, int dta, Cell* dst)
    {
        temp = tmp ;
        data = dta ;
        dest = dst ;
        result = true ;
    }

void MemNode::showData()
    { 
       printf("[Time:%lu, Data:%i, Match:%i, dest:%p] ", temp, data, match_counter , dest )  ; 
    } 
