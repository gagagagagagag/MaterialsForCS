#include <string>
#include "Node.h"
#include "Graph.h"

int Node::getValue() const {
    return value;
}

void Node::setValue(int value) {
    Node::value = value;
}

Node::Node(int value, int index) : value(value), index(index) {
    checked = false;
}

std::vector<Node *> Node::getConnectedNodes() const {
    std::vector<Node *> connectedNodesToSend;

    for (Edge * edge : this->connectedNodes) {
        Node * conNode = edge->getConnectedNode();
        if (conNode != nullptr) {
            connectedNodesToSend.push_back(conNode);
        }
    }

    return connectedNodesToSend;
}

std::vector<Edge *> Node::getEdges() const {
    return this->connectedNodes;
}

void Node::connectToNode(Node &node, bool undirectedGraph, int edgeWeight) {
    this->addANodeToConnectedNodes(node, edgeWeight);
    if (undirectedGraph) {
        node.addANodeToConnectedNodes(*this, edgeWeight);
    }
}

void Node::addANodeToConnectedNodes(Node &node, int edgeWeight) {
    this->connectedNodes.push_back(new Edge(this, &node, edgeWeight));
}

void Node::disconnectFromNode(Node &node, bool undirectedGraph) {
    this->removeANodeFromConnectedNodes(node);
    if (undirectedGraph) {
        node.removeANodeFromConnectedNodes(*this);
    }
}

void Node::removeANodeFromConnectedNodes(Node &node) {
    std::vector<Edge *>::iterator it;
    it = std::find_if(this->connectedNodes.begin(), this->connectedNodes.end(), [node](Edge * edge) -> bool {
        return edge->getConnectedNode(node) != nullptr;
    });

    if (it != this->connectedNodes.end()) {
        this->connectedNodes.erase(it);
    }
}

bool Node::isNodeEven() {
    return (this->connectedNodes.size() % 2 == 0);
}

bool Node::isChecked() const {
    return checked;
}

void Node::setChecked(bool checked) {
    Node::checked = checked;
}

std::ostream &operator<<(std::ostream &out, const Node &node) {
    out << "Index " << node.index << ": " << "The node with index " << node.index << (node.value != -1 ? " and value: " : "") << (node.value != -1 ? std::to_string(node.value) : "") << " is connected to nodes with indexes: ";

//    for (const auto * connectedNode : node.getConnectedNodes()){
//        out << connectedNode->getIndex() << " ";
//    }

    for (const auto * edge : node.getEdges()){
        out << edge->getConnectedNode()->getIndex() << "(" << edge->getWeight() << ")" << " ";
    }

    out << std::endl;

    return out;
}

Node::Node(int index) : index(index) {
    value = -1;
    checked = false;
}

int Node::getIndex() const {
    return this->index;
}

void Node::setIndex(int index) {
    Node::index = index;
}

int Node::getConnectedNodesLength() const {
    return this->connectedNodes.size();
}
