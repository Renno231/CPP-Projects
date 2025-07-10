/*
Name: Renno231
Status: Completed
Description: This file contains the Stack class object header.
    
*/

#ifndef STACK_H
#define STACK_H

#include "data.h"
#include <stdexcept>

class Stack {

public:

    
     Stack(int);  // constructor
    ~Stack();  // destructor

    int getsize();
    bool pop(Data*);
    bool peek(Data*);
    bool push(int, string*);
    bool isEmpty();

private:

    int top;
    int size;
    Data **stack;
};

#endif 

