#include <vector>
#include <ostream>
#include "Edge.h"


#ifndef PLAYGROUND_NODE_H
#define PLAYGROUND_NODE_H


class Node {
public:
    explicit Node(int value, int index);

    Node(int index);

    int getValue() const;

    void setValue(int value);

    std::vector<Node *> getConnectedNodes() const;

    std::vector<Edge *> getEdges() const;

    void connectToNode(Node& node, bool undirectedGraph, int edgeWeight = 1);

    void disconnectFromNode(Node &node, bool undirectedGraph);

    int getConnectedNodesLength() const;

    bool isNodeEven();

    bool isChecked() const;

    void setChecked(bool checked);

    friend std::ostream &operator<<(std::ostream &os, const Node &node);

    int getIndex() const;

    void setIndex(int index);

private:
    int value;
    bool checked;
    int index;
//    std::vector<Node *> connectedNodes;
    std::vector<Edge *> connectedNodes;

    void addANodeToConnectedNodes(Node& node, int edgeWeight);
    void removeANodeFromConnectedNodes(Node& node);

};


#endif //PLAYGROUND_NODE_H
