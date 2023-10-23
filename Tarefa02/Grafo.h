#ifndef GRAFO_H

#define GRAFO_H

#include <list>
#include <vector>
#include "Aresta.h"

class Grafo {
public:
    Grafo(int numVertices);
    void checkVertex(int v);
    void checkEdge(Aresta e);
    int numVertices();
    int numEdges();
    void insertEdge(Aresta e);
    void removeEdge(Aresta e);
    void potenciais_comparsas(int src);
    void print();
private:
    int numVertices_;
    int numEdges_;
    std::vector<int> visited_;
    std::vector<int> distances_;
    std::vector<std::list<int > > adjList_;
};

#endif /* GRAFO_H */
