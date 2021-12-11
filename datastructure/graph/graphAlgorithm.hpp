#include "graph.hpp"

// 普里姆算法 -- 矩阵
void PrimMst(GraphMatrix G){
    // 创建布尔数组来记录每个节点是否访问过
    vector<bool> isVisited(G.getNodesNum());
    isVisited[0] = true; // 0号节点标记访问过
    int count = 0; // 记录总权值
    // 从0号节点开始
    for(int k = 1; k < G.getNodesNum(); ++k){
        // h1 : 出发节点，h2 : 到达节点
        // minWeight : 所有访问过的点可以辐射到的边里最小的边
        int minWeight = INF;
        int h1 = -1, h2 = -1;
        // i : 固定一个访问过的节点
        for(int i = 0; i < G.getEdgesNum(); ++i){
            // j : 固定一个没访问过的节点
            for(int j = 0; j < G.getEdgesNum(); ++j){
                // i访问过、j没访问过，且这条边最小
                if(isVisited[i] && !isVisited[j] && G.getWeight()[i][j] < minWeight){
                    minWeight = G.getWeight()[i][j];
                    h1 = i;
                    h2 = j;
                }
            }
        }
        // 打印出来这次更新的边
        cout << " <"<<G.getNode(h1)<<","<<G.getNode(h2)<<"> = " << minWeight <<endl;
        isVisited[h2] = true; // 标记访问过
        count += minWeight;
    }
    cout << "weight sum = " << count <<endl;
}

// 获得某个点的终点
int getEnd(vector<int> &ends, int index){
    while(ends[index] != 0){
        index = ends[index];
    }
    return index;
}
// 克鲁斯卡尔算法 -- 矩阵
void KrusKalMst(GraphMatrix G){
    int count = 0;
    // 得到一个图的所有边
    vector<Edges> edges = G.generateEdges();
    // 按边的大小从小到大排列
    sort(edges.begin(), edges.end(), [](Edges e1, Edges e2){ return e1.weight < e2.weight;});
    // 创建终点节点
    vector<int> ends(G.getEdgesNum());
    // 从小到大遍历所有的边
    for(auto edg : edges){
        // 得到这这条边的起点和终点
        int p1 = edg.start;
        int p2 = edg.end;
        // 查看两个节点的终点
        int e1 = getEnd(ends, p1);
        int e2 = getEnd(ends, p2);
        // 如果不同，说明一定是无环的
        if(e1 != e2){
            ends[e1] = e2; // 更新，e1的后继是e2
            // 输出
            cout << " <"<<G.getNode(p1)<<","<<G.getNode(p2)<<"> = " << edg.weight <<endl;
            count += edg.weight; // 累加权值
        }
    }
    cout << "weight sum = " << count <<endl;
}

// 普里姆 -- 链表
void PrimMst(GraphList G){
    int count = 0;
    vector<bool> visited(G.getNodesNum());
    visited[0] = true;
    for(int k = 1; k < G.getNodesNum(); ++k){
        int minWeight = INF, h1 = -1, h2 = -1;
        for(int i = 0; i < G.getNodesNum(); ++i){
            auto j = G.getEdges()[i]->next;
            while(j){
                if(visited[i] && !visited[j->val] && j->weight < minWeight){
                    h1 = i;
                    h2 = j->val;
                    minWeight = j->weight;
                }
                j = j->next;
            }
        }
        cout << " <"<<G.getNodes()[h1]<<","<<G.getNodes()[h2]<<"> = " << minWeight <<endl;
        visited[h2] = true;
        count += minWeight;
    }
    cout << "weight sum = " << count <<endl;
}

// 克鲁斯卡尔 -- 链表
void KrusKalMst(GraphList G){
    int count = 0;
    auto edges = G.generateEdges();
    sort(edges.begin(), edges.end(), [](Edges e1, Edges e2){return e1.weight < e2.weight;});
    vector<int> ends(G.getNodesNum());
    for(auto edg : edges){
        int e1 = getEnd(ends, edg.start);
        int e2 = getEnd(ends, edg.end);
        if(e1 != e2){
            ends[e1] = e2;
            cout << " <"<<G.getNodes()[edg.start]<<","<<G.getNodes()[edg.end]<<"> = " << edg.weight <<endl;
            count += edg.weight;
        }
    }
    cout << "weight sum = " << count <<endl;
}


// Dijkstra -- 矩阵


// Floyd -- 矩阵


// Dijkstra -- 链表


// Floyd -- 链表

