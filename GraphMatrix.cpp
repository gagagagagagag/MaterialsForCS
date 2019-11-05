//
// Created by Jakub Przywara on 2019-10-30.
//

#include <iostream>
#include "GraphMatrix.h"

std::ostream &operator<<(std::ostream &out, const GraphMatrix &matrixGraph) {
    out << std::endl;
    out << "---------------------------------------" << std::endl;
    out << "Matrix Graph contents:" << std::endl;

    for (int i = 0; i < matrixGraph.nodesInTheGraph.size(); i++) {
        out << "Node " << i << " is connected to nodes: ";
        for (int j = 0; j < matrixGraph.nodesInTheGraph.at(i).size(); j++) {
            if (j == i) {
                continue;
            }

            if (matrixGraph.nodesInTheGraph.at(i).at(j) == 1) {
                out << j << " ";
            }
        }
        out << std::endl;
    }

    return out;
}

GraphMatrix::GraphMatrix() {}

void GraphMatrix::addANodeToTheGraph() {
    this->nodesInTheGraph.push_back(std::vector<int>());

    int target = this->nodesInTheGraph.at(0).size() + 1;
    for (int i = 0; i < this->nodesInTheGraph.size(); i++){
        while (this->nodesInTheGraph.at(i).size() < target) {
            this->nodesInTheGraph.at(i).push_back(0);
        }
    }

}

void GraphMatrix::connectNodes(int indexA, int indexB) {
    if (indexA < this->nodesInTheGraph.size() && indexB < this->nodesInTheGraph.size()) {
        this->nodesInTheGraph.at(indexA).at(indexB) = 1;
        this->nodesInTheGraph.at(indexB).at(indexA) = 1;
    }
}

void GraphMatrix::disconnectNodes(int indexA, int indexB) {
    if (indexA < this->nodesInTheGraph.size() && indexB < this->nodesInTheGraph.size()) {
        this->nodesInTheGraph.at(indexA).at(indexB) = 0;
        this->nodesInTheGraph.at(indexB).at(indexA) = 0;
    }
}
