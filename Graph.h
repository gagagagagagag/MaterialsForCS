#ifndef PLAYGROUND_GRAPH_H
#define PLAYGROUND_GRAPH_H

#include <iostream>
#include "Node.h"

class Graph {
public:
    Graph(bool undirectedGraph = true);

    Node * addANodeToTheGraph(int value);

    Node * addANodeToTheGraph();

    void removeANodeFromTheGraph(int index);

    const std::vector<Node *> &getNodesInTheGraph() const;

    Node * getNodeWithIndex(int index);

    Node * getFirstNotNullNode();

    int getNodesCount();

    int getNotNullNodesCount();

    void connectNodes(Node& a, Node& b, int edgeWeight = 1);

    void connectNodes(int indexA, int indexB, int edgeWeight = 1);

    void disconnectNodes(Node& a, Node& b);

    void disconnectNodes(int indexA, int indexB);

    bool isGraphEven();

    bool isGraphConnected();

    bool isGraphConnectedDFS(bool verbose = false);

    bool checkIfNodesAreConnectedDFS(int indexA, int indexB, bool verbose = false);

    bool checkIfNodesAreConnectedDFSRecursion(Node * nextNode, Node* source, Node * target, bool verbose = false);

    bool isGraphEuler();

    Node* vertexMaxDegree();

    Node* vertexMinDegree();

    bool isIsomorphicToTriangle();

    friend std::ostream& operator<<(std::ostream& out, const Graph& graph){

        out << std::endl;
        out << "---------------------------------------" << std::endl;
        out << "Graph contents (edge weights are provided in brackets):" << std::endl;

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
    bool undirectedGraph;

    void isGraphConnectedDFSRecursion(Node &node, bool verbose = false);
};




#endif //PLAYGROUND_GRAPH_H
