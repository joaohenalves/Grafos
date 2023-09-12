#include "Graph.h"
#include <iostream>

using namespace std;

Graph::Graph(int numVertices) {
    numVertices_ = numVertices;
    numEdges_ = 0;
    adjList_.resize(numVertices);
}

void Graph::insertEdge(Edge e) {
    if(e.v1 == e.v2) return;
    bool exists = false;
    for(auto egd : adjList_[e.v1]) {
        if(egd == e.v2) {
            exists = true;
            break;
        }
    }
    if(!exists) {
        adjList_[e.v1].push_front(e.v2);
        adjList_[e.v2].push_front(e.v1);
        numEdges_++;
    }
}

bool Graph::removeEdgePart(int src, int dest) {
    for(auto it = adjList_[src].begin(); it != adjList_[src].end(); it++) {
        if(*it == dest) {
            adjList_[src].erase(it);
            return true;
        }
    }
    return false;
}

void Graph::removeEdge(Edge e) {
    if(removeEdgePart(e.v1, e.v2) && removeEdgePart(e.v2, e.v1))
        numEdges_--;
}

void Graph::removeVertex(int v) {
    numEdges_ -= adjList_[v].size();
    numVertices_--;
    for(int i = 0; i < numVertices_; i++) {
        if(i >= v) adjList_[i] = move(adjList_[i + 1]);
        for(auto it = adjList_[i].begin(); it != adjList_[i].end(); ) {
            if(*it == v) {
                it = adjList_[i].erase(it);
            }
            else {
                if(*it > v) {
                    (*it)--;
                }
                it++;
            }
        }
    }
    adjList_.pop_back();
}

void Graph::print() {
    for(int i = 0; i < numVertices_; i++) {
        cout << i << ":";
        for(auto v : adjList_[i]) {
            cout << " " << v; 
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