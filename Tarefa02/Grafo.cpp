#include "Grafo.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

Grafo::Grafo(int numVertices) {
    if (numVertices <= 0) {
        throw(invalid_argument("Erro no construtor Grafo(int): o numero de "
            "vertices " + to_string(numVertices) + " eh invalido!"));
    }
    numVertices_ = numVertices;
    numEdges_ = 0;
    visited_.resize(numVertices);
    adjList_.resize(numVertices);
    distances_.resize(numVertices);
}

void Grafo::checkVertex(int v) {
    if ((v < 0) || (v >= numVertices_)) {
        throw out_of_range("Indice de vertice invalido: " + to_string(v));
    }
}

void Grafo::checkEdge(Aresta e) {
    checkVertex(e.v1);
    checkVertex(e.v2);
}

void Grafo::insertEdge(Aresta e) {
    checkEdge(e);
    if(e.v1 == e.v2) return;
    if(find(adjList_[e.v1].begin(), adjList_[e.v1].end(), e.v2) == adjList_[e.v1].end()) {
        adjList_[e.v1].push_front(e.v2);
        adjList_[e.v2].push_front(e.v1);
        numEdges_++;
    }
}

void Grafo::removeEdge(Aresta e) {
    auto it = find(adjList_[e.v1].begin(), adjList_[e.v1].end(), e.v2);
    if(it != adjList_[e.v1].end()) {
        adjList_[e.v1].erase(it);
        adjList_[e.v2].erase(find(adjList_[e.v2].begin(), adjList_[e.v2].end(), e.v1));
        numEdges_--;
    }
}

void Grafo::print() {
    for(int i = 0; i < numVertices_; i++) {
        cout << i << ":";
        for(auto e : adjList_[i]) {
            cout << " " << e; 
        }
        cout << "\n";
    }
}

void Grafo::potenciais_comparsas(int src) {
    fill(visited_.begin(), visited_.end(), 0);
    fill(distances_.begin(), distances_.end(), INT_MAX);
    queue<int> q;
    int temp;
    distances_[src] = 0;
    visited_[src] = 1;
    q.push(src);
    while(!q.empty()) {
        temp = q.front();
        q.pop();
        for(auto e : adjList_[temp]) {
            if(!visited_[e]) {
                q.push(e);
                distances_[e] = distances_[temp] + 1;
                visited_[e] = 1;
            }
        }
    }
    cout << src << ":";
    for(int i = 0; i < numVertices_; i++) {
        if(distances_[i] < 4 && i != src) cout << " " << i;
    }
    cout << "\n";
}

int Grafo::numEdges() {
    return numEdges_;
}

int Grafo::numVertices() {
    return numVertices_;
}