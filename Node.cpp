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
    return this->connectedNodes;
}

void Node::connectToNode(Node &node) {
    this->addANodeToConnectedNodes(node);
    node.addANodeToConnectedNodes(*this);
}

void Node::addANodeToConnectedNodes(Node &node) {
    this->connectedNodes.push_back(&node);
}

void Node::disconnectFromNode(Node &node) {
    this->removeANodeFromConnectedNodes(node);
    node.removeANodeFromConnectedNodes(*this);
}

void Node::removeANodeFromConnectedNodes(Node &node) {
    std::vector<Node *>::iterator it;
    it = std::find(this->connectedNodes.begin(), this->connectedNodes.end(), &node);

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

    for (const auto * connectedNode : node.getConnectedNodes()){
        out << connectedNode->getIndex() << " ";
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
