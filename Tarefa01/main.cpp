#include "Graph.h"
#include "Edge.h"
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    try {
        int v, o, v1, v2;
        char op;
        cin >> v >> o;
        Graph graph(v);
        while(o--) {
            cin >> op;
            switch (op) {
                case 'I':
                    cin >> v1 >> v2;
                    graph.insertEdge(Edge(v1, v2));
                    break;
                case 'R':
                    cin >> v1 >> v2;
                    graph.removeEdge(Edge(v1, v2));
                    break;
                case 'E':
                    cout << graph.numEdges() << "\n";
                    break;
                case 'Q':
                    cin >> v1;
                    graph.removeVertex(v1);
                    break;
                case 'N':
                    cout << graph.numVertices() << "\n";
                    break;
                case 'P':
                    graph.print();
                    break;
            }
        }
    } catch (const exception &e) {
        cerr << "exception: " << e.what() << "\n";
    }

    return 0;
}
