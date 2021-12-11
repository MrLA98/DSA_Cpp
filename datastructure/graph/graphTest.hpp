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

    PrimMst(graph);
    KrusKalMst(graph);

    PrimMst(listG);
    KrusKalMst(listG);
}