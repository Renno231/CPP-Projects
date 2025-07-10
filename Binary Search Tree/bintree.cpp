/*
Name: Renno231
Status: Complete
Description: This file contains the Binary Tree class object.
*/

#include "bintree.h"

BinTree::BinTree() {
    root = NULL;
    count = 0;
}

BinTree::~BinTree() {
    this->clear();
}

bool BinTree::isEmpty(){
    return count == 0;
}

int BinTree::getCount(){
    return count;
}

bool BinTree::getRootData(Data* dat){
    bool gotdata = false;
    if(root){
        dat->information = root->data.information;
        dat->id = root->data.id;
        gotdata = true;
    }else{
        dat->information = "";
        dat->id = -1;
    }
    return gotdata;
}

void BinTree::displayTree(){
    cout << "DISPLAY TREE" << endl << "==============================================" << endl;
    cout << (this->isEmpty() ? "Tree is empty. " : "Tree is NOT empty.") << endl << "Height: " << this->getHeight() << endl << "Node count: " << count << endl << endl;
    this->displayPreOrder();
    cout << endl;
    this->displayInOrder();
    cout << endl;
    this->displayPostOrder();
    cout << endl;
    cout << "==============================================" << endl;
}

void BinTree::clear(){
    this->clear(root);
    count = 0;
    root = NULL;
}

void BinTree::clear(DataNode* subroot){
    if (subroot){
        if(subroot->left){
            this->clear(subroot->left);
        }
        if (subroot->right){
            this->clear(subroot->right);
        }
        subroot->right = NULL;
        subroot->left = NULL;
        delete subroot;
    }
}

bool BinTree::addNode(int id, const string* newdata){
    bool addednode = false;
    if(id > 0 && !newdata->empty()){
        DataNode *newNode = new DataNode;
        newNode->data.id = id; 
        newNode->data.information = *newdata;
        newNode->left = NULL;
        newNode->right = NULL;
        if(root){
            addednode = this->addNode(newNode, &root);
        }else{
            root = newNode;
            addednode = true;
        }
        if (addednode){
            count++;
        }else{
            delete newNode;
        }
    }
    return addednode;
}

bool BinTree::addNode(DataNode* newnode, DataNode** subroot){
    bool addednode = false;
    if ((*subroot)->data.id < newnode->data.id){
        if ((*subroot)->right){
            addednode = this->addNode(newnode, &(*subroot)->right);
        }else{
            (*subroot)->right = newnode;
            addednode = true;
        }
    }else if((*subroot)->data.id > newnode->data.id){
        if ((*subroot)->left){
            addednode = this->addNode(newnode, &(*subroot)->left);
        }else{
            (*subroot)->left = newnode;
            addednode = true;
        }
    }
    return addednode;
}

DataNode* BinTree::minValueNode(DataNode* node) {
    DataNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

bool BinTree::removeNode(int id){
    bool removednode = false;
    int tempcount = count;
    if (root) {
        root = this->removeNode(id, root);
        removednode = count < tempcount;
    }
    return removednode;
}

DataNode* BinTree::removeNode(int id, DataNode* subroot){
    if(subroot->data.id == id){
        DataNode* tempNode = NULL;
        if (subroot->right && subroot->left){
            tempNode = this->minValueNode(subroot->right);
            subroot->data.id = tempNode->data.id;
            subroot->data.information = tempNode->data.information;
            subroot->right = this->removeNode(tempNode->data.id, subroot->right);
        }else if(subroot->right || subroot->left){
            tempNode = subroot->right ? subroot->right : subroot->left;
            delete subroot;
            subroot = tempNode;
        }else{
            delete subroot;
            subroot = NULL;
        }
        count--;
    }else{
        if (subroot->data.id < id){
            if (subroot->right){
                subroot->right = this->removeNode(id, subroot->right);
            }
        }else if(subroot->data.id > id){
            if (subroot->left){
                subroot->left = this->removeNode(id, subroot->left);
            }
        }
    }
    return subroot;
}

bool BinTree::getNode(Data* emptydata, int id){
    bool gotnode = false;
    if(id > 0 && root){
        gotnode = this->getNode(emptydata, id, root);
    }
    return gotnode;
}

bool BinTree::getNode(Data* emptydata, int id, DataNode* subroot){
    bool hasid = subroot->data.id == id;
    if (!hasid){
        if (subroot->data.id < id){
            if (subroot->right){
                hasid = this->getNode(emptydata, id, subroot->right);
            }
        }else if(subroot->data.id > id){
            if (subroot->left){
                hasid = this->getNode(emptydata, id, subroot->left);
            }
        }
    }
    if(hasid){
        emptydata->id = subroot->data.id;
        emptydata->information = subroot->data.information;
    }
    return hasid;
}

bool BinTree::contains(int id){
    bool doescontain = false;
    if (id > 0 && root){
        if (root->data.id==id){
            doescontain = true;
        }else{
            doescontain = contains(id, root);
        }
    }
    return doescontain;
}

bool BinTree::contains(int id, DataNode* subroot){
    bool hasid = subroot->data.id == id;
    if (!hasid){
        if (subroot->data.id < id){
            if (subroot->right){
                hasid = this->contains(id, subroot->right);
            }
        }else if(subroot->data.id > id){
            if (subroot->left){
                hasid = this->contains(id, subroot->left);
            }
        }
    }
    return hasid;
}

int BinTree::getHeight(){
    int height = 0;
    if (root){
        height = this->getHeight(root);
        height++;
    }
    return height;
}

int BinTree::getHeight(DataNode* subroot){
    int lheight = 0, rheight = 0;
    if (subroot->right){
        rheight++;
        rheight+=this->getHeight(subroot->right);
    }
    if(subroot->left){
        lheight++;
        lheight+=this->getHeight(subroot->left);
    }
    return std::max(lheight, rheight);
}

void BinTree::displayPreOrder(){
    cout << "Pre-Order Traversal" << endl;
    this->displayPreOrder(root);
}

void BinTree::displayPreOrder(DataNode* subroot){
   if (subroot) {
        cout << subroot->data.id << " " << subroot->data.information << endl;
        if (subroot->left) {
            displayPreOrder(subroot->left);
        }
        if (subroot->right) {
            displayPreOrder(subroot->right);
        }
        
    }
}

void BinTree::displayPostOrder(){
    cout << "Post-Order Traversal" << endl;
    this->displayPostOrder(root);
}

void BinTree::displayPostOrder(DataNode* subroot){
    if (subroot) {
        if (subroot->left) {
            displayPostOrder(subroot->left);
        }
        if (subroot->right) {
            displayPostOrder(subroot->right);
        }
        cout << subroot->data.id << " " << subroot->data.information << endl;
    }
}

void BinTree::displayInOrder(){
    cout << "In-Order Traversal" << endl;
    this->displayInOrder(root);
}

void BinTree::displayInOrder(DataNode* subroot){
    if (subroot) {
        if (subroot->left) {
            displayInOrder(subroot->left);
        }
        cout << subroot->data.id << " " << subroot->data.information << endl;
        if (subroot->right) {
            displayInOrder(subroot->right);
        }
    }
}