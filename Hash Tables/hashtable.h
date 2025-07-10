/*
Name: Renno231
Status: Completed
Description: This file is the headerfile for the HashTable class object.
    
*/

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define HASHTABLESIZE 15

#include "linkedlist.h"
#include <iostream>
#include <string>
#include <bits/stdc++.h>



using std::cout;
using std::endl;
using std::string;

class HashTable {

public:

    
     HashTable();
    ~HashTable();

    bool insertEntry(int, std::string*);
    std::string getData(int);
    bool removeEntry(int);
    int getCount();
    void printTable();


private:

    int hash(int);
    int count;
    LinkedList table[HASHTABLESIZE];
};

#endif 