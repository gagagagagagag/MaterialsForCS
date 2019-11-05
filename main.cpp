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

    graph->removeANodeFromTheGraph(3);

    std::cout << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << std::endl;

    std::cout << (graph->isGraphEven() ? "Graph is even." : "Graph is not even.") << std::endl;

    std::cout << (graph->isGraphConnected() ? "Graph is connected." : "Graph is not connected.") << std::endl;

    std::cout << (graph->isGraphEuler() ? "Graph is Euler." : "Graph is not Euler.") << std::endl;

    Node * mostConnectionsNode = graph->vertexMaxDegree();

    std::cout << "The node with the most connections has an index: " << mostConnectionsNode->getIndex() << " and has " << mostConnectionsNode->getConnectedNodesLength() << " connections" << std::endl;

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