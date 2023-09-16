#include "Graph.h"
#include "Edge.h"
#include <iostream>

using namespace std;

int main() {
    try {
        int v, e, v1, v2;
        char op;
        cin >> v >> e;
        Graph graph(v);
        for(int i = 0; i < e; i++) {
            cin >> v1 >> v2;
            graph.insertEdge(Edge(v1, v2));
        }
        while(cin >> op) {
            if(op == 'X') {
                cout << graph.countComp() << " Connected components\n";
            } else {
                cout << (graph.checkCycle() ? "This graph contains a cycle\n" : "This graph does not contain a cycle\n");
            }
        }
    }
    catch (const exception &e) {
        cerr << "exception: " << e.what() << "\n";
    }

    return 0;
}
