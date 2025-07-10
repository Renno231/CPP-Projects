/*
Name: Renno231
Status: Completed
Description: This file is the headerfile for the linkedlist class object.
    
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "data.h"
#include <iostream>
#include <string>
#include <bits/stdc++.h>

class LinkedList {

public:

    
     LinkedList();  // constructor
    ~LinkedList();  // destructor

    bool addNode(int, string*);
    bool deleteNode(int);
    bool getNode(int, Data*);
    void printList(bool=false);
    int getCount();
    bool clearList();
    bool exists(int);


private:
    Node * newNode(int, string*);
    void positionNode(Node*, Node*, int);
    Node *head;
};

#endif 