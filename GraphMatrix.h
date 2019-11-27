//
// Created by Jakub Przywara on 2019-10-30.
//

#ifndef PLAYGROUND_GRAPHMATRIX_H
#define PLAYGROUND_GRAPHMATRIX_H


#include <vector>
#include <ostream>

class GraphMatrix {
public:
    GraphMatrix(bool undirectedGraph = true);

    void addANodeToTheGraph();

    void removeANodeFromTheGraph(int index);

    void connectNodes(int indexA, int indexB, float connectionWeight = 1);

    void disconnectNodes(int indexA, int indexB);

    void printMatrix();

    friend std::ostream &operator<<(std::ostream &os, const GraphMatrix &matrix);

private:
    std::vector<std::vector<float>> nodesInTheGraph;
    std::vector<int> removedNodes;
    bool undirectedGraph;

};


#endif //PLAYGROUND_GRAPHMATRIX_H
