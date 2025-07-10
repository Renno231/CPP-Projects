/*
Name: Renno231
Status: 
Description: This file contains the Weighted Graph class object.
*/

#include "wgraph.h"

WeightGraph::WeightGraph() {
}

WeightGraph::~WeightGraph() {
}

bool WeightGraph::isEmpty(){
    return nodes.size() == 0;
}

int WeightGraph::getSize(){
    return nodes.size();
}

bool WeightGraph::clear(){
    bool cleared = false;
    nodes.clear();
    weights.clear();
    cleared = true;
    return cleared;
}

int WeightGraph::indexOf(int id){
    int index = -1;
    bool found = false;
    if(id > -1){
        for (int i = 0; i < nodes.size() && !found; i++ ){
            found = nodes[i].id == id;
            if (found){
                index = i;
            }
        }
    }
    return index;
}

bool WeightGraph::addNode(int id){
    bool addednode = false;
    if(indexOf(id)==-1){
        Node newNode;
        newNode.id = id;
        nodes.push_back(newNode);
        weights.emplace_back();
        addednode = true;
    }
    return addednode;
}

bool WeightGraph::linkNodes(int id1, int id2, int weight){
    bool linked = false;
    int index1 = indexOf(id1), index2 = indexOf(id2);
    if (index1 > -1 && index2 > -1 && id1!=id2 && weight>0 && !areConnected(id1, id2)){
        weights[index1].push_back(std::make_pair(index2, weight));
        weights[index2].push_back(std::make_pair(index1, weight));
        linked = true;
    }
    return linked;
}

bool WeightGraph::removeNode(int id){
    bool removednode = false;
    int index = indexOf(id);
    if (index > -1){
        nodes.erase(nodes.begin()+index);
        for (int i = 0; i < weights[index].size(); i++){
            bool detached = false;
            for (int ii = 0; ii < weights[i].size() && !detached; ii++){ 
                if(weights[i][ii].first == index){
                    weights[i].erase(weights[i].begin()+ii);
                    detached = true;
                }
            }
        }
        weights.erase(weights.begin()+index);
        removednode = true;
    }
    return removednode;
}

int WeightGraph::getNode(int id){
    return indexOf(id);
}

int WeightGraph::getWeight(int id1, int id2){
    int weight = -1;
    int index1 = indexOf(id1), index2 = indexOf(id2);
    if (index1 > -1 && index2 > -1 && index1!=index2){
        bool foundweight = false;
        for (int i = 0; i < weights[index1].size() && !foundweight; i++){
            if(weights[index1][i].first == index2){
                foundweight = true;
                weight = weights[index1][i].second;
            }   
        }
    }
    return weight;
}

bool WeightGraph::changeWeight(int id1, int id2, int newWeight){
    bool changedweight = false;
    int index1 = indexOf(id1), index2 = indexOf(id2);
    if (index1 > -1 && index2 > -1 && index1!=index2 && newWeight > 0){
        bool connected = false;
        for (int i = 0 ; i < weights[index1].size() && !connected; i++){
            connected = weights[index1][i].first == index2;
            if (connected){
                weights[index1][i].second = newWeight;
            }
        }
        connected = false;
        for (int i = 0 ; i < weights[index2].size() && !connected; i++){
            connected = weights[index2][i].first == index1;
            if (connected){
                weights[index2][i].second = newWeight;
            }
        }
    }
    return changedweight;
}

bool WeightGraph::areConnected(int id1, int id2){
    bool connected = false;
    int index1 = indexOf(id1), index2 = indexOf(id2);
    if (index1 > -1 && index2 > -1 && index1!=index2){
        for (int i = 0 ; i < weights[index1].size() && !connected; i++){
            connected = weights[index1][i].first == index2;
        }
    }
    return connected;
}

vector<int> WeightGraph::getConnections(int id){
    vector< int > connections;
    int index = indexOf(id);
    if (id > -1){
        for (int i = 0 ; i < weights[index].size(); i++){
            connections.push_back(weights[index][i].first);
        }
    }
    return connections;
}

pair<unsigned int, vector<unsigned int>> WeightGraph::getPath(int id1, int id2){
    vector<unsigned int> idealpath;
    unsigned int idealpathlength = 0;
    const unsigned int totalnodes = nodes.size();
    int nodeA = indexOf(id1), nodeB = indexOf(id2);
    if (nodeA > -1 && nodeB > -1 && nodeA!=nodeB) {
        bool foundpath = false, completedsearch = false;
        unsigned int currentnode = nodeA, totaliterations = 0, shortestpath = INT_MAX, lastnode = currentnode;

        pair<unsigned int, unsigned int> paths[totalnodes][totalnodes];
        unsigned int pathlengths[totalnodes];
        pair<unsigned int, unsigned int> checks[totalnodes];
        for (int cpair = 0; cpair < totalnodes; cpair++){
            checks[cpair].first = 0, checks[cpair].second = weights[cpair].size(); 
        }
        for (int pathindex = 0; pathindex < totalnodes; pathindex++){
            if (pathindex!=currentnode){ 
                paths[0][pathindex].first = INT_MAX;
                paths[0][pathindex].second = INT_MAX;
            }else{
                paths[0][pathindex].first = 0; 
            }
        }

        for (int i = 0; i < totalnodes; i ++){
            pathlengths[i] = paths[0][i].first;
        }
        for (int row = 0; row < totalnodes && !completedsearch; row++){
            for (int nindex = 0; nindex < weights[currentnode].size(); nindex++){
                pair<int, int> neighbor = weights[currentnode][nindex];
                if ((neighbor.second + pathlengths[currentnode] < pathlengths[neighbor.first] || pathlengths[neighbor.first] == INT_MAX) && checks[neighbor.first].first < checks[neighbor.first].second ){ //if the current weight is less than 
                    
                    paths[row][neighbor.first].first = neighbor.second;
                    paths[row][neighbor.first].second = currentnode;
                    pathlengths[neighbor.first] = neighbor.second + pathlengths[currentnode];
                    checks[neighbor.first].first++;
                    checks[currentnode].first++;
                }
            }
            shortestpath = INT_MAX, lastnode = currentnode;
            for (int i = 0; i < totalnodes; i ++){
                if (shortestpath > pathlengths[i] && checks[i].first < checks[i].second ){
                    shortestpath = pathlengths[i];
                    currentnode = i;
                }
            }
            
            if (lastnode != currentnode){ 
                for (int column = 0; column < totalnodes; column++){ 
                    paths[row+1][column].first = paths[row][column].first, paths[row+1][column].second = paths[row][column].second;
                }
                
            }else{
                completedsearch = true;
                totaliterations = row;
            }
        }
        
        int prevnode = paths[totaliterations][nodeB].second;
        idealpathlength+=paths[totaliterations][nodeB].first;
        if (prevnode <= totalnodes){
            idealpath.push_back(nodeB);
            for (int row = totaliterations-1; row >= 0 && !foundpath; row--){
                if (prevnode <= totalnodes){
                    idealpathlength+=paths[row][prevnode].first;
                    idealpath.insert(idealpath.begin(), prevnode);
                    foundpath = prevnode == nodeA;
                    prevnode = paths[row][prevnode].second;
                }
            }
        }
        if (!foundpath){
            idealpath.clear();
            idealpathlength = INT_MAX;
        }
    
    }
    return std::make_pair(idealpathlength, idealpath);
}

void WeightGraph::displayGraph(){
    int totalconnections = 0;
    for (int node = 0; node < weights.size(); node ++ ){
        totalconnections = weights[node].size();
        cout << "Node " << node << " has ID " << nodes[node].id;
        if (totalconnections > 0){
            cout << " and " << totalconnections << " connections: ";
            int nindex = 0;
            for (pair<int, int> neighbor : weights[node]){
                cout << "(Node = " << neighbor.first << ", Weight = " << neighbor.second << ", ID = " << nodes[neighbor.first].id <<  " )";
                if (nindex < totalconnections-1){
                    cout << ", ";
                }
                nindex++;
            }
        }else{
            cout << " and no connections.";
        }
        cout << endl;
    }
}