// TBD
#include <iostream>

class Graph {
private:
    int vertices {};
    int edges {};

public:
    class Edge {
    public:
        int src {};
        int dest {};
    };

    Edge edge[];

    Graph(int vertices, int edges) {
        Edge edge[edges] {};
        // int *a { new int[MAX] };
        // Edge *edge { new Edge[edges] };
        for (int i = 0; i < edges; i++)
            edge[i] = Edge {};
    }
};

int main() {
    int noVertices { 5 };
    int noEdges { 8 };

    Graph g { noVertices, noEdges };

    g.edge[0].src = 1;
    g.edge[0].dest = 2;
    
    g.edge[1].src = 1;
    g.edge[1].dest = 3;

    g.edge[2].src = 1;
    g.edge[2].dest = 4;

    g.edge[3].src = 2;
    g.edge[3].dest = 4;

    g.edge[4].src = 2;
    g.edge[4].dest = 5;

    g.edge[5].src = 3;
    g.edge[5].dest = 4;

    g.edge[6].src = 3;
    g.edge[6].dest = 5;

    g.edge[7].src = 4;
    g.edge[7].dest = 5;

    for (int i = 0; i < noEdges; i++)
        std::cout << g.edge[i].src << " -> " << g.edge[i].dest << '\n';

    return 0;
}
