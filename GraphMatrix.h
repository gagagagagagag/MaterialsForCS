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

    void connectNodes(int indexA, int indexB, int connectionWeight = 1);

    void disconnectNodes(int indexA, int indexB);

    friend std::ostream &operator<<(std::ostream &os, const GraphMatrix &matrix);

private:
    std::vector<std::vector<int>> nodesInTheGraph;
    bool undirectedGraph;

};


#endif //PLAYGROUND_GRAPHMATRIX_H
