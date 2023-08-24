#include "Graph.h"
#include "Edge.h"
#include <iostream>

using namespace std;

int main() {
    try {
        Graph graph(5);
        Edge e(3, 4);
        graph.insertEdge(e);
        graph.insertEdge(Edge(4, 2));
        graph.print();
    }
    catch (const exception &e) {
        cerr << "exception: " << e.what() << "\n";
    }

    return 0;
}
