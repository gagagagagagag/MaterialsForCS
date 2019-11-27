// Algorythms Graph

#include <iostream>
#include "Graph.h"
#include "GraphMatrix.h"

int main() {

    // List Graph

    auto * graph = new Graph();

    graph->addANodeToTheGraph();

    graph->addANodeToTheGraph();

    graph->addANodeToTheGraph();

    graph->addANodeToTheGraph();

    graph->addANodeToTheGraph();

    graph->connectNodes(0, 1);

    graph->connectNodes(1, 2);

    graph->connectNodes(1, 3);

    graph->connectNodes(2, 3);

    graph->connectNodes(3, 4);

    std::cout << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << std::endl;

    std::cout << (graph->isGraphEven() ? "Graph is even." : "Graph is not even.") << std::endl;

    std::cout << (graph->isGraphConnected() ? "Graph is connected. (BFS)" : "Graph is not connected. (BFS)") << std::endl;

    std::cout << (graph->isGraphConnectedDFS() ? "Graph is connected. (DFS)" : "Graph is not connected. (DFS)") << std::endl;

    std::cout << (graph->isGraphEuler() ? "Graph is Eulerian." : "Graph is not Eulerian.") << std::endl;

    std::cout << (graph->isIsomorphicToTriangle() ? "There exists a subgraph in the graph that is isomorphic to a graph containing three nodes in a triangular pattern." : "There does not exist a subgraph in the graph that is isomorphic to a graph containing three nodes in a triangular pattern.") << std::endl;

    Node * mostConnectionsNode = graph->vertexMaxDegree();

    if (mostConnectionsNode != nullptr) std::cout << "The node with the most connections has an index: " << mostConnectionsNode->getIndex() << " and has " << mostConnectionsNode->getConnectedNodesLength() << " connections" << std::endl;

    Node * leastConnectionsNode = graph->vertexMinDegree();

    if (leastConnectionsNode != nullptr) std::cout << "The node with the least connections has an index: " << leastConnectionsNode->getIndex() << " and has " << leastConnectionsNode->getConnectedNodesLength() << " connections" << std::endl;

    std::cout << "Checking node connection with DFS:" << std::endl;
    bool result = graph->checkIfNodesAreConnectedDFS(2, 4);
    std::cout << "The nodes are" << (result ?  "" : " not") << " connected." << std::endl;

    std::cout << *graph;

    // Matrix Graph

    auto * matrixGraph = new GraphMatrix(true);

    matrixGraph->addANodeToTheGraph();

    matrixGraph->addANodeToTheGraph();

    matrixGraph->addANodeToTheGraph();

    matrixGraph->addANodeToTheGraph();

    matrixGraph->addANodeToTheGraph();

    matrixGraph->addANodeToTheGraph();

    matrixGraph->connectNodes(0, 3);

    matrixGraph->connectNodes(1, 4, 10);

    matrixGraph->connectNodes(2, 3);

    matrixGraph->connectNodes(5, 1);

    std::cout << *matrixGraph;

    return 0;
}