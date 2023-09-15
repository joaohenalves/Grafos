#include "Graph.h"
#include <iostream>
#include <algorithm>

using namespace std;

Graph::Graph(int numVertices) {
    numVertices_ = numVertices;
    numEdges_ = 0;
    visited_.resize(numVertices);
    adjList_.resize(numVertices);
}

void Graph::insertEdge(Edge e) {
    if(e.v1 == e.v2) return;
    if(find(adjList_[e.v1].begin(), adjList_[e.v1].end(), e.v2) == adjList_[e.v1].end()) {
        adjList_[e.v1].push_front(e.v2);
        adjList_[e.v2].push_front(e.v1);
        numEdges_++;
    }
}

void Graph::removeEdge(Edge e) {
    auto it = find(adjList_[e.v1].begin(), adjList_[e.v1].end(), e.v2);
    if(it != adjList_[e.v1].end()) {
        adjList_[e.v1].erase(it);
        adjList_[e.v2].erase(find(adjList_[e.v2].begin(), adjList_[e.v2].end(), e.v1));
        numEdges_--;
    }
}

void Graph::print() {
    for(int i = 0; i < numVertices_; i++) {
        cout << i << ":";
        for(auto e : adjList_[i]) {
            cout << " " << e; 
        }
        cout << "\n";
    }
}

void Graph::dfs(int v) {
    visited_[v] = 1;
    for(auto e : adjList_[v]) {
        if(!visited_[e]) dfs(e);
    }
}

int Graph::countComp() {
    fill(visited_.begin(), visited_.end(), 0);
    int i, counter = 0;
    for(i = 0; i < numVertices_; i++) {
        if(!visited_[i]) {
            dfs(i);
            counter++;
        }
    }
    return counter;
}

bool Graph::dfsCycle(int u, int v) {
    visited_[v] = 1;
    for(auto e : adjList_[v]) {
        if(!visited_[e]) {
            if(dfsCycle(v, e)) return true;
        } else {
            if(e != u) return true;
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