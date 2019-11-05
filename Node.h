//
// Created by Jakub Przywara on 2019-10-29.
//

#include <vector>
#include <ostream>


class Graph;

#ifndef PLAYGROUND_NODE_H
#define PLAYGROUND_NODE_H


class Node {
public:
    explicit Node(int value, int index);

    Node(int index);

    int getValue() const;

    void setValue(int value);

    std::vector<Node *> getConnectedNodes() const;

    void connectToNode(Node& node);

    void disconnectFromNode(Node &node);

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
    std::vector<Node *> connectedNodes;

    void addANodeToConnectedNodes(Node& node);
    void removeANodeFromConnectedNodes(Node& node);

};


#endif //PLAYGROUND_NODE_H
