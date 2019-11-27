#ifndef PLAYGROUND_EDGE_H
#define PLAYGROUND_EDGE_H


class Node;

class Edge {
    Node * edgeFrom;
    Node * edgeTo;
    int weight;
public:
    Edge(Node *edgeFrom, Node *edgeTo, int weight = 1);

    int getWeight() const;

    void setWeight(int weight);

    Node * getConnectedNode(const Node &sourceNode) const;

    Node * getConnectedNode() const;
};


#endif //PLAYGROUND_EDGE_H
