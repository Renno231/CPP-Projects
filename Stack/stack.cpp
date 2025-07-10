/*
Name: Renno231
Status: Completed
Description: This file contains the Stack class object.
    
*/

#include "stack.h"

Stack::Stack(int s) {
    if (s < 1){
        throw std::overflow_error("Stack size must be 2 or larger");
    }
    
    top = -1;
    stack = new Data*[s];
    size = s;
    
}

Stack::~Stack() {
    for (int i = 0; i < top; i++){
        delete stack[i];
    }
    delete [] stack;
}

int Stack::getsize(){
    return size;
}

bool Stack::push(int i, string *str) {
    bool pushed = false;
    if (top < size - 1 && i > -1 && !str->empty()) {
        Data *newdata = new Data;
        newdata->id = i;
        newdata->information = *str;
        stack[++top] = newdata;
        pushed = true;
    }
    return pushed;
}

bool Stack::pop(Data *empty) {
    bool popped = false;
    if (top > -1) {
        empty->id = stack[top]->id;
        empty->information = stack[top]->information;
        delete stack[top--];
        popped = true; 
    }else{
        empty->id = -1;
        empty->information = "";
    }
    return popped;
}

bool Stack::peek(Data *empty) {
    bool peeked = false;
    if (top > -1) {
        empty->id = stack[top]->id;
        empty->information = stack[top]->information;
        peeked = true; 
    }else{
        empty->id = -1;
        empty->information = "";
    }
    return peeked;
}

bool Stack::isEmpty() {
    return top < 0;
}