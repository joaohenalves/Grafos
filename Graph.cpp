#include "Graph.h"
#include <iostream>

using namespace std;

Graph::Graph(int numVertices) {
    numVertices_ = numVertices;
    numEdges_ = 0;
    matrix_.resize(numVertices);
    for(int i = 0; i < numVertices; i++) {
        matrix_[i].resize(numVertices, 0);
    }
}

void Graph::insertEdge(Edge e) {
    if((matrix_[e.v1][e.v2] == 0) && (e.v1 != e.v2)) {
        matrix_[e.v1][e.v2] = 1;
        matrix_[e.v2][e.v1] = 1;
        numEdges_++;
    }
}

void Graph::removeEdge(Edge e) {
    if(matrix_[e.v1][e.v2] == 1) {
        matrix_[e.v1][e.v2] = 0;
        matrix_[e.v2][e.v1] = 0;
        numEdges_--;
    }
}

void Graph::print() {
    for(int i = 0; i < numVertices_; i++) {
        cout << i << ":";
        for(int j = 0; j < numVertices_; j++) {
            if(matrix_[i][j] == 1) cout << " " << j; 
        }
        cout << "\n";
    }
}

int Graph::numEdges() {
    return numEdges_;
}

int Graph::numVertices() {
    return numVertices_;
}