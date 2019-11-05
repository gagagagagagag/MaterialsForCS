//
// Created by Jakub Przywara on 2019-10-29.
//

#ifndef PLAYGROUND_GRAPH_H
#define PLAYGROUND_GRAPH_H

#include <iostream>
#include "Node.h"

class Graph {
public:
    Graph();

    Node * addANodeToTheGraph(int value);

    Node * addANodeToTheGraph();

    void removeANodeFromTheGraph(int index);

    const std::vector<Node *> &getNodesInTheGraph() const;

    Node * getNodeWithIndex(int index);

    int getNodesCount();

    void connectNodes(Node& a, Node& b);

    void connectNodes(int indexA, int indexB);

    void disconnectNodes(Node& a, Node& b);

    void disconnectNodes(int indexA, int indexB);

    bool isGraphEven();

    bool isGraphConnected();

    bool isGraphEuler();

    Node* vertexMaxDegree();

    friend std::ostream& operator<<(std::ostream& out, const Graph& graph){

        out << std::endl;
        out << "---------------------------------------" << std::endl;
        out << "Graph contents:" << std::endl;

        int i = 0;

        for (const Node * node : graph.nodesInTheGraph) {
            if (node == nullptr) {
                out << "Index " << i << ": Removed" << std::endl;
                i++;
                continue;
            }

            out << *node;
            i++;
        }

        return out;
    }

private:
    std::vector<Node *> nodesInTheGraph;
};


#endif //PLAYGROUND_GRAPH_H
