#include "Edge.h"

Edge::Edge(Node *edgeFrom, Node *edgeTo, int weight) : edgeFrom(edgeFrom), edgeTo(edgeTo), weight(weight){}


int Edge::getWeight() const {
    return weight;
}

void Edge::setWeight(int weight) {
    Edge::weight = weight;
}

Node *Edge::getConnectedNode(const Node &sourceNode) const {
    if (&sourceNode == this->edgeFrom) {
        return this->edgeTo;
    } else {
        return nullptr;
    }
}

Node *Edge::getConnectedNode() const {
    return this->edgeTo;
}
