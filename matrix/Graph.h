#ifndef GRAPH_H

#define GRAPH_H

#include <vector>
#include "Edge.h"

class Graph {
public:
    Graph(int numVertices);
    int numVertices();
    int numEdges();
    void insertEdge(Edge e);
    void removeEdge(Edge e);
    void dfs(int v);
    int isConnected();
    bool dfsCycle(int u, int v);
    bool checkCycle();
    void print();
private:
    int numVertices_;
    int numEdges_;
    std::vector<int> visited_;
    std::vector<std::vector<int > > matrix_;
};

#endif /* GRAPH_H */
