/*
Name: Renno231
Status: 
Description: This file contains the  Weighted Graph class object header.
*/


#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H

#include "data.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <bits/stdc++.h>

using std::cout;
using std::endl;
using std::vector;
using std::pair;

class WeightGraph {

public:

    
     WeightGraph(); 
    ~WeightGraph(); 

    bool isEmpty();
    int getSize();
    bool clear();
    bool addNode(int);
    bool linkNodes(int, int, int); // node a (id), node b (id), weight
    bool removeNode(int);
    int getNode(int);
    bool changeWeight(int, int, int); //node a (id), node b (id), and the new weight
    bool areConnected(int, int); //returns if node a (id) is connected to node b (id)
    int getWeight(int, int);
    vector<int> getConnections(int); //id
    pair<unsigned int, vector<unsigned int>>  getPath(int, int);
    void displayGraph();

private:

    int indexOf(int); //id returns index or -1 if null
    vector<Node> nodes; //1d array of Nodes
    vector<vector<pair<int, int>>> weights; //1d vector array of pair<node, weight>

    
};

#endif