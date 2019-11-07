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

    graph->connectNodes(0, 1);

    graph->connectNodes(0, 2);

    graph->addANodeToTheGraph();

    graph->addANodeToTheGraph();

    graph->connectNodes(2, 3);

    graph->connectNodes(3, 4);

    graph->connectNodes(4, 0);

    graph->connectNodes(1, 2);

    graph->connectNodes(0, 5);

    graph->removeANodeFromTheGraph(4);

    std::cout << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << std::endl;

    std::cout << (graph->isGraphEven() ? "Graph is even." : "Graph is not even.") << std::endl;

    std::cout << (graph->isGraphConnected() ? "Graph is connected." : "Graph is not connected.") << std::endl;

    std::cout << (graph->isGraphEuler() ? "Graph is Euler." : "Graph is not Euler.") << std::endl;

    std::cout << (graph->isIsomorphicToTriangle() ? "There exists a subgraph in the graph that is isomorphic to a graph containing three nodes in a triangular pattern." : "There does not exist a subgraph in the graph that is isomorphic to a graph containing three nodes in a triangular pattern.") << std::endl;

    Node * mostConnectionsNode = graph->vertexMaxDegree();

    if (mostConnectionsNode != nullptr) std::cout << "The node with the most connections has an index: " << mostConnectionsNode->getIndex() << " and has " << mostConnectionsNode->getConnectedNodesLength() << " connections" << std::endl;

    Node * leastConnectionsNode = graph->vertexMinDegree();

    if (leastConnectionsNode != nullptr) std::cout << "The node with the least connections has an index: " << leastConnectionsNode->getIndex() << " and has " << leastConnectionsNode->getConnectedNodesLength() << " connections" << std::endl;

    std::cout << *graph;

    // Matrix Graph

    auto * matrixGraph = new GraphMatrix();

    matrixGraph->addANodeToTheGraph();

    matrixGraph->addANodeToTheGraph();

    matrixGraph->addANodeToTheGraph();

    matrixGraph->addANodeToTheGraph();

    matrixGraph->addANodeToTheGraph();

    matrixGraph->addANodeToTheGraph();

    matrixGraph->connectNodes(0, 3);

    matrixGraph->connectNodes(1, 4);

    matrixGraph->connectNodes(2, 3);

    matrixGraph->connectNodes(5, 1);

    std::cout << *matrixGraph;

    return 0;
}