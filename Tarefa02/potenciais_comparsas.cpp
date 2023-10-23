#include "Aresta.h"
#include "Grafo.h"
#include <iostream>

using namespace std;

int main() {
    try {
        int v, e, v1, v2, queries, suspect;
        char op;
        cin >> v >> e;
        Grafo graph(v);
        for(int i = 0; i < e; i++) {
            cin >> v1 >> v2 >> op;
            if(op == 'W') graph.insertEdge(Aresta(v1, v2));
        }
        cin >> queries;
        while(queries--) {
            cin >> suspect;
            graph.potenciais_comparsas(suspect);
        }
    }
    catch (const exception &e) {
        cerr << "exception: " << e.what() << "\n";
    }

    return 0;
}
