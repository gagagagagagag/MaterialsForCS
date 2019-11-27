//
// Created by Jakub Przywara on 2019-10-30.
//

#include <iostream>
#include <iomanip>
#include "GraphMatrix.h"

std::ostream &operator<<(std::ostream &out, const GraphMatrix &matrixGraph) {
    out << std::endl;
    out << "---------------------------------------" << std::endl;
    out << "Matrix Graph contents (edge weights are provided in brackets):" << std::endl;

    for (int i = 0; i < matrixGraph.nodesInTheGraph.size(); i++) {

        if (std::find(matrixGraph.removedNodes.begin(), matrixGraph.removedNodes.end(), i) != matrixGraph.removedNodes.end()) {
            out << "Node " << i << " has been removed." << std::endl;
            continue;
        }

        out << "Node " << i << " is connected to nodes: ";
        for (int j = 0; j < matrixGraph.nodesInTheGraph.at(i).size(); j++) {

            if (matrixGraph.nodesInTheGraph.at(i).at(j) != 0) {
                out << j << "(" << matrixGraph.nodesInTheGraph.at(i).at(j) << ")" << " ";
            }
        }
        out << std::endl;
    }

    return out;
}

void GraphMatrix::printMatrix() {
    std::cout << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Matrix Graph:" << std::endl;

    for (int i = 0; i < this->nodesInTheGraph.size(); i++) {

        if (std::find(this->removedNodes.begin(), this->removedNodes.end(), i) != this->removedNodes.end()) {
            continue;
        }

        for (int j = 0; j < this->nodesInTheGraph.at(i).size(); j++) {

            if (std::find(this->removedNodes.begin(), this->removedNodes.end(), j) != this->removedNodes.end()) {
                continue;
            }

            std::cout << std::setw(5) << std::right << this->nodesInTheGraph.at(i).at(j);
        }
        std::cout << std::endl;
    }
}

GraphMatrix::GraphMatrix(bool undirectedGraph) : undirectedGraph(undirectedGraph) {}

void GraphMatrix::addANodeToTheGraph() {
    this->nodesInTheGraph.push_back(std::vector<float>());

    int target = this->nodesInTheGraph.at(0).size() + 1;
    for (int i = 0; i < this->nodesInTheGraph.size(); i++) {
        while (this->nodesInTheGraph.at(i).size() < target) {
            this->nodesInTheGraph.at(i).push_back(0);
        }
    }
}

void GraphMatrix::connectNodes(int indexA, int indexB, float connectionWeight) {
    if (indexA < this->nodesInTheGraph.size() && indexB < this->nodesInTheGraph.size()) {
        this->nodesInTheGraph.at(indexA).at(indexB) = connectionWeight;
        if (this->undirectedGraph) {
            this->nodesInTheGraph.at(indexB).at(indexA) = connectionWeight;
        }
    }
}

void GraphMatrix::disconnectNodes(int indexA, int indexB) {
    if (indexA < this->nodesInTheGraph.size() && indexB < this->nodesInTheGraph.size()) {
        this->nodesInTheGraph.at(indexA).at(indexB) = 0;
        if (this->undirectedGraph) {
            this->nodesInTheGraph.at(indexB).at(indexA) = 0;
        }
    }
}

void GraphMatrix::removeANodeFromTheGraph(int index) {
    if (index < this->nodesInTheGraph.size()) {
        this->removedNodes.push_back(index);

        for (int i = 0; i < this->nodesInTheGraph[index].size(); i++) {
            this->nodesInTheGraph[index][i] = 0;
            this->nodesInTheGraph[i][index] = 0;
        }
    }
}
