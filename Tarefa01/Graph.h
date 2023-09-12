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
    bool removeEdgePart(int src, int dest);
    void removeEdge(Edge e);
    void removeVertex(int v);
    void print();
private:
    int numVertices_;
    int numEdges_;
    std::vector<std::list<int> > adjList_;
};

#endif /* GRAPH_H */