#include "main.h"

int main(int argc, char** argv) {
    srand(time(NULL));

    int graphSize = random_range(10, 25);
    int randomIDs[graphSize];
    int randomWeights[graphSize];
    for (int i = 0; i < graphSize; i++){
        randomIDs[i] = random_range(50,250);
        randomWeights[i] = random_range(1, 20); 
    } 
    int duplicateID = randomIDs[random_range(0,graphSize-1)];
    int randStartNode = randomIDs[random_range(0,graphSize-1)], randEndNode;
    do{
        randEndNode = randomIDs[random_range(0,graphSize-1)];
    }while(randStartNode == randEndNode);

    cout << "Creating test graph...." << endl;
    WeightGraph testGraph;
    cout << "   Created test graph!" << endl << endl;
    
    cout << "The graph is " << (testGraph.isEmpty() ? "" : "not ") << "empty." << endl;
    cout << "Populating graph..." << endl;
    for (int i = 0; i < graphSize; i++){
        bool added = testGraph.addNode(randomIDs[i]);
        cout << "     " << "Attempt " << i+1 << "... " << (added ? "Added node ": "Failed to add node ") << "with ID " << randomIDs[i] << endl;
    }
    cout << "The graph now has " << testGraph.getSize() << " nodes." << endl;
    cout << endl << "Attempting to add a duplicate... " << (testGraph.addNode(duplicateID) ? "successfully added " : "failed to add ") << duplicateID << endl << endl << "Displaying graph..." << endl;
    testGraph.displayGraph();
    cout << endl << "Testing node linking..." << endl;
    for (int i = 0; i < graphSize; i++){
        int randomNode = random_range(0,graphSize-1);
        while(randomNode==i){
            randomNode = random_range(0,graphSize-1);
        }
        cout << "Attempting to link " << randomIDs[i] << " to " << randomIDs[randomNode] << " with weight " << randomWeights[i] << "... " << (testGraph.linkNodes(randomIDs[i], randomIDs[randomNode], randomWeights[i]) ? "success.": "failed.") << endl;
    }
    cout << endl << "Displaying graph..." << endl;
    testGraph.displayGraph();

    cout << endl << "Testing Dijkstras shortest path algo by finding the shortest path between nodes with IDs " << randStartNode << " and " << randEndNode << endl;
    pair<unsigned int, vector<unsigned int>> pathdata = testGraph.getPath(randStartNode, randEndNode);
    cout << "The shortest path was " << (pathdata.first!=INT_MAX && pathdata.first!=0 ? "" : "not " ) << "found." << endl;
    cout << "The path has a length of " << pathdata.first << endl;
    for (int i = 0; i < pathdata.second.size(); i++){
        cout << pathdata.second[i];
        if(i+1<pathdata.second.size()){
            cout << " -> ";
        }
    }
    cout << endl;
    return 0;
}

