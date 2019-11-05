//
// Created by Jakub Przywara on 2019-10-29.
//

#include <iostream>
#include "Graph.h"

Graph::Graph() {
}

Node * Graph::addANodeToTheGraph(int value) {
    Node * newNode = new Node(value, this->getNodesCount());
    this->nodesInTheGraph.push_back(newNode);
    return newNode;
}

Node *Graph::addANodeToTheGraph() {
    Node * newNode = new Node(this->getNodesCount());
    this->nodesInTheGraph.push_back(newNode);
    return newNode;
}

const std::vector<Node *> &Graph::getNodesInTheGraph() const {
    return nodesInTheGraph;
}

Node *Graph::getNodeWithIndex(int index) {
    if (index >= this->nodesInTheGraph.size()) {
        return nullptr;
    }

    return this->nodesInTheGraph.at(index);
}

int Graph::getNodesCount() {
    return this->nodesInTheGraph.size();
}

void Graph::removeANodeFromTheGraph(int index) {
    if (index < this->getNodesCount() && this->getNodeWithIndex(index) != nullptr) {

        for (auto & node : this->getNodeWithIndex(index)->getConnectedNodes()){
            this->disconnectNodes(*node, *this->getNodeWithIndex(index));
        }

        std::vector<Node *>::iterator it;
        it = std::find(this->nodesInTheGraph.begin(), this->nodesInTheGraph.end(), this->getNodeWithIndex(index));

        if (it != this->nodesInTheGraph.end()) {
            delete *it;
            *it = nullptr;
        }
    } else {
        std::cout << "Index " << index << " does not exist, so the node was not removed" << std::endl;
    }
}

void Graph::connectNodes(Node &a, Node &b) {
    a.connectToNode(b);
}

void Graph::connectNodes(int indexA, int indexB) {
    if (indexA < this->getNodesCount() && indexB <= this->getNodesCount() && this->getNodeWithIndex(indexA) != nullptr && this->getNodeWithIndex(indexB) != nullptr) {
        this->getNodeWithIndex(indexA)->connectToNode(*this->getNodeWithIndex(indexB));
    } else {
        std::cout << "Index " << indexA << " or " << indexB << " does not exist, so the nodes were not connected" << std::endl;
    }
}

void Graph::disconnectNodes(Node &a, Node &b) {
    a.disconnectFromNode(b);
}

void Graph::disconnectNodes(int indexA, int indexB) {
    if (indexA < this->getNodesCount() && indexB <= this->getNodesCount() && this->getNodeWithIndex(indexA) != nullptr && this->getNodeWithIndex(indexB) != nullptr) {
        this->getNodeWithIndex(indexA)->disconnectFromNode(*this->getNodeWithIndex(indexB));
    } else {
        std::cout << "Index " << indexA << " or " << indexB << " does not exist, so the nodes were not disconnected" << std::endl;
    }
}

bool Graph::isGraphEven() {
    for (Node * node : this->nodesInTheGraph) {
        if (node == nullptr) {
            continue;
        }

        if (!node->isNodeEven()) {
            return false;
        }
    }
    return true;
}

bool Graph::isGraphConnected() {
    std::vector<Node *> placesToCheck;

    if (this->nodesInTheGraph.empty()) {
        return false;
    }

    if (this->nodesInTheGraph.size() == 1) {
        return true;
    }

    // Set all checked values to false
    for (Node * node : this->nodesInTheGraph) {
        if (node == nullptr) {
            continue;
        }

        node->setChecked(false);
    }

    // Take the first node, get the connections and mark it checked
    for (Node * node : this->getNodeWithIndex(0)->getConnectedNodes()) {
        placesToCheck.push_back(node);
    }

    this->getNodeWithIndex(0)->setChecked(true);

    // Check nodes until there is nothing to check
    while (!placesToCheck.empty()) {
        Node * nodeToCheck = placesToCheck.back();
        placesToCheck.pop_back();

        if (nodeToCheck->isChecked()){
            continue;
        }

        for (Node * node : nodeToCheck->getConnectedNodes()) {
            placesToCheck.push_back(node);
        }

        nodeToCheck->setChecked(true);
    }

    // Check if all the nodes are checked
    for (Node * node : this->nodesInTheGraph) {
        if (node == nullptr) {
            continue;
        }

        if (!node->isChecked()) {
            return false;
        }
    }
    return true;
}

bool Graph::isGraphEuler() {
    return this->isGraphEven() && this->isGraphConnected();
}

Node* Graph::vertexMaxDegree() {
    std::vector<Node *>::iterator it;
    it = std::max_element(this->nodesInTheGraph.begin(), this->nodesInTheGraph.end(), [](Node * a, Node * b){
        if (a == nullptr || b == nullptr) {
            return false;
        }
        return a->getConnectedNodesLength() < b->getConnectedNodesLength();
    });

    return *it;
}


