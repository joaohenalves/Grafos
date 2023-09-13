#include "Graph.h"
#include <iostream>

using namespace std;

Graph::Graph(int numVertices) {
    numVertices_ = numVertices;
    numEdges_ = 0;
    visited_.resize(numVertices);
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

void Graph::dfs(int v) {
    visited_[v] = 1;
    for(int i = 0; i < numVertices_; i++) {
        if(matrix_[v][i] == 1 && !visited_[i]) dfs(i);
    }
}

int Graph::isConnected() {
    int i, counter = 0;
    for(i = 0; i < numVertices_; i++) {
        if(!visited_[i] && counter <= 1) {
            dfs(i);
            counter++;
        } else if(counter > 1) return counter;
    }
    for(i = 0; i < numVertices_; i++) visited_[i] = 0;
    return counter;
}

bool Graph::dfsCycle(int u, int v) {
    visited_[v] = 1;
    for(int i = 0; i < numVertices_; i++) {
        if(matrix_[v][i] == 1) {
            if(!visited_[i]) {
                if(dfsCycle(v, i)) return true;
            } else {
                if(i != u) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Graph::checkCycle() {
    fill(visited_.begin(), visited_.end(), 0);
    for(int i = 0; i < numVertices_; i++) {
        if(!visited_[i]) {
            if(dfsCycle(-1, i)) return true;
        }
    }
    return false;
}

int Graph::numEdges() {
    return numEdges_;
}

int Graph::numVertices() {
    return numVertices_;
}