/*
Name: Renno231
Status: Completed
Description: This file contains the linkedlist class object.
    
*/

#include "linkedlist.h"

LinkedList::LinkedList() {
    head = NULL;
}

LinkedList::~LinkedList() {
    this->clearList();
}

Node* LinkedList::newNode(int id, string *newdata){
    Node *newNode = new Node;
    newNode->data.id = id; 
    newNode->data.data = *newdata;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void LinkedList::positionNode(Node *newNode,Node *currentnode, int id){
    if (head){
        if (id < currentnode->data.id){
            newNode->next = currentnode;
            if(currentnode->prev){
                newNode->prev = currentnode->prev;
                currentnode->prev->next = newNode;
            }
            currentnode->prev = newNode;
            if (currentnode == head){
                head = newNode;
            }
        }else{
            newNode->prev = currentnode;
            currentnode->next = newNode;
        }
    }else{
        head = newNode;
    }
}

bool LinkedList::addNode(int id, string *newdata){
    bool addednode = false, duplicateid = false, listpositionfound = false;
    if(id > 0 && !newdata->empty()){
        Node *currentnode = head;
        if (currentnode){
            duplicateid = id == currentnode->data.id;
            if (currentnode->data.id < id && !duplicateid){
                while(!listpositionfound){
                    duplicateid = id == currentnode->data.id;
                    if (currentnode->next  && currentnode->data.id < id && !duplicateid){
                        currentnode = currentnode->next;
                    }else{
                        listpositionfound = true;
                    }     
                }
            }
        }
        if (!duplicateid ){
            this->positionNode(this->newNode(id, newdata), currentnode, id);
            addednode = true;
        }
    }
    return addednode;
}

bool LinkedList::deleteNode(int id){
    bool deleted = false;
    Node *current = head;
    while(!deleted && current){ 
        deleted = current->data.id == id;
        if (deleted){
            if (current->next){
                current->next->prev = current->prev;
            }
            if (current->prev){
                current->prev->next = current->next;
            }else{
                head = current->next;
            }
            delete current;
            
        }else{
            current = current->next;
        } 
    }
    return deleted;
}

bool LinkedList::getNode(int id, Data *empty){
    std::string tempstring = "";
    bool foundnode = false;
    Node *current = head;
    while (!foundnode && current){
        foundnode = id == current->data.id;
        tempstring = current->data.data;
        current = current->next;
    }
    if (foundnode){
        empty->id = id;
        empty->data = tempstring;
    }else{
        empty->id = -1;
        empty->data = "";
    }
    return foundnode;
}

void LinkedList::printList(bool reversed){
    Node *current = head;
    std::string printout = "";
    while(current){
        printout.append(std::to_string(current->data.id));
        current = current->next; 
        if (current){
            printout.append(" -> ");
        }
    }
    std::cout << printout << std::endl;
}

int LinkedList::getCount(){
    int counter = 0;
    Node *current = head;
    while(current){       
        counter++;
        current = current->next; 
    }
    return counter;
}

bool LinkedList::clearList(){
    bool cleared = false;
    Node *current = head;
    if(current){
        if (current->next){
            current = current->next;
            while(current){
                delete current->prev;
                current = current->next;
            }
        }else{
            delete current;
        }
        cleared = true;
    }
    head = NULL;
    return cleared;
}

bool LinkedList::exists(int id){
    bool foundid = false;
    Node *current = head;
    while(!foundid && current){       
        foundid = id == current->data.id;
        if (!foundid){
            current = current->next;
        } 
    }
    return foundid;
}