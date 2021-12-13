#include "graphAlgorithm.hpp"

void GraphInterface(){
    vector<char> nodes = {'a','b','c','d','e','f','g'};
    vector<vector<int>> weights = {
        {INF, 7, 6, INF, INF, 4, INF},
        {7, INF, 12, INF, INF, INF, INF},
        {6, 12, INF, 2, INF, INF, INF},
        {INF, INF, 2, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, 6, INF},
        {4, INF, INF, INF, 6, INF, 3},
        {INF, INF, INF, INF, INF, 3, INF}
    };
    GraphMatrix graph(nodes, weights);
    graph.dfs();
    graph.bfs();
    GraphList listG(graph);
    listG.dfs();
    listG.bfs();
    GraphMatrix g2(listG);

    cout << "# matrix test:\n";
    cout << "# Prim:\n";
    PrimMst(graph);
    cout << "# KrusKal:\n";
    KrusKalMst(graph);
    cout << "# Dijkstra:\n";
    Dijkstra(graph, 5);
    cout << "# Floyd:\n";
    Floyd(graph);

    cout << "# list test:\n";
    cout << "# Prim:\n";
    PrimMst(listG);
    cout << "# KrusKal:\n";
    KrusKalMst(listG);
    cout << "# Dijkstra:\n";
    Dijkstra(listG, 5);
    cout << "# Floyd:\n";
    Floyd(listG);
}