#ifndef GRAPH_H

#define GRAPH_H

#include <list>
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
    int countComp();
    bool dfsCycle(int u, int v);
    bool checkCycle();
    void print();
private:
    int numVertices_;
    int numEdges_;
    std::vector<int> visited_;
    std::vector<std::list<int > > adjList_;
};

#endif /* GRAPH_H */
