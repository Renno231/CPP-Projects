/*
Name: Renno231
Status: 
Description: This file contains the HashTable class object.
    
*/

#include "hashtable.h"

HashTable::HashTable() {
    count = 0;
}

HashTable::~HashTable() {
}

bool HashTable::insertEntry(int id, string* str){
    bool inserted = false;
    int pos = hash(id);
    if (id > 0 && !str->empty() ) {
        inserted = table[pos].addNode(id, str);
        if (inserted){
            count++;
        }
    }
    return inserted;
}

string HashTable::getData(int id){
    int pos = hash(id);
    Data emptydata;
    emptydata.data = "";
    if (pos >= 0){
        table[pos].getNode(id, &emptydata);
    }
    return emptydata.data;
}

bool HashTable::removeEntry(int id){
    int pos = hash(id);
    bool removed = false;
    if (pos >= 0){
        removed = table[pos].deleteNode(id);
        if (removed) {
            count--;
        }
    }
    return removed;
}

int HashTable::getCount(){
    return count;
}

void HashTable::printTable(){
    for (int i = 0; i < HASHTABLESIZE; i++){
        std::cout << "Entry " << i << ": ";
        if (table[i].getCount()>0){
            table[i].printList();
        }else{
            std::cout << "EMPTY" << std::endl;
        }
    }
}

int HashTable::hash(int i){
    return i % HASHTABLESIZE;
}