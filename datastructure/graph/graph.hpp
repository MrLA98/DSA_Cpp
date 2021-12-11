#include <iostream>
#include <vector>
#include <deque>

using namespace std;

const int INF = 65535;

class GraphList;

class GraphMatrix{
    vector<char> nodes; // 节点
    int nodesNum; // 节点个数
    int edgsNum; // 边的个数
    vector<vector<int>> weights; // 邻接矩阵

    // 更新边的个数
    void updateEdges(){
        edgsNum = 0;
        for(int i = 0; i < weights.size(); ++i){
            for(int j = i+1; j < weights.front().size(); ++j){
                if(weights[i][j]!= INF) ++edgsNum;
            }
        }
    }

    // dfs的递归函数
    void dfs(int index, vector<bool> &isVisited){
        isVisited[index] = true; // 标志为已访问
        cout << " [" << nodes[index]<< "] "; // 打印
        int next = getNext(index, -1); // 得到该节点的第一个联通节点
        while(next != -1){
            if(!isVisited[next]){
                dfs(next, isVisited);
            }
            next = getNext(index, next);
        }
    }

    // bfs的实际实现
    void bfs(int index, vector<bool> &isVisited){
        // 打印并标记
        cout << " [" << nodes[index] << "] ";
        isVisited[index] = true;
        // 队列尾部插入当前节点下标
        deque<int> queue;
        queue.push_back(index);
        // 只要队列不为空就广度遍历
        while(!queue.empty()){
            // 弹出一个作为广度遍历的头
            index = queue.front();
            queue.pop_front();
            // 找与这个头相连的所有节点
            int next = getNext(index, -1);
            // 遍历
            while(next != -1){
                if(!isVisited[next]){ // 没访问过
                    // 打印并标记
                    cout << " [" << nodes[next] << "] ";
                    isVisited[next] = true;
                    // 插入队列尾部
                    queue.push_back(next);
                }
                // 找下一个
                next = getNext(index, next);
            }
        }
    }

    // 以start为起点的其他终点，不包括cur
    int getNext(int start, int cur){
        for(int i = cur+1; i < nodesNum; ++i){
            if(weights[start][i] != INF){
                return i;
            }
        }
        return -1;
    }

    // 给定一个节点字符，返回它的下标
    int getIndex(char node){
        for(int i = 0; i < nodes.size(); ++i){
            if(nodes[i] == node){
                return i;
            }
        }
        return -1;
    }

public:
    GraphMatrix(vector<char>& nod, vector<vector<int>>& wei){
        nodes = nod;
        weights = wei;
        nodesNum = nod.size();
        updateEdges();
    }

    GraphMatrix(GraphList &G);

    char getNode(int index){
        return nodes[index];
    }

    // dfs -- 对外接口
    void dfs(){
        vector<bool> isVisited(nodesNum);
        for(int i = 0; i < nodesNum; ++i){
            if(!isVisited[i]){
                dfs(i, isVisited);
            }
        }
    }

    // bfs
    void bfs(){
        vector<bool> isVisited(nodesNum);
        for(int i = 0; i < nodesNum; ++i){
            if(!isVisited[i]){
                bfs(i, isVisited);
            }
        }
    }

    vector<char>& getNoedes(){
        return nodes;
    }

    vector<vector<int>>& getWeight(){
        return weights;
    }
};

// 边节点
class GNodes{
public:
    int val;
    int weight;
    GNodes* next;
    GNodes():val(0),weight(INF),next(NULL){}
    GNodes(int v, int wei):val(v),weight(wei),next(NULL){} 
    
    bool isEmpty(){
        return next == nullptr;
    }

    void add(int index, int wei){
        GNodes* cur = this;
        while(1){
            if(cur->next == nullptr || cur->next->val > index){
                GNodes *node = new GNodes(index,wei);
                node->next = cur->next;
                cur->next = node;
                return;
            }
            else if(cur->next->val == index){
                cout << "# node existed!\n";
                return;
            }
            cur = cur->next;
        }
    }
};

// 链表图
class GraphList{
    vector<char> nodes; // 节点
    int nodesNum;
    int edgesNum;
    vector<GNodes*> edges; // 边
    void initEdges(){
        for(int i = 0; i < edges.size(); ++i){
            edges[i] = new GNodes();
        }
    }

public:
    GraphList(GraphMatrix& G){
        nodes = G.getNoedes();
        nodesNum = nodes.size();
        edges.resize(nodesNum); 
        initEdges();
        edgesNum = 0;
        for(int i = 0; i < nodesNum; ++i){
            for(int j = i + 1; j < nodesNum; ++j){
                int w = G.getWeight()[i][j];
                if(w != INF){
                    edges[i]->add(j,w);
                    edges[j]->add(i,w);
                    ++edgesNum;
                }
            }
        }
    }

    vector<GNodes*>& getEdges(){
        return edges;
    }

    vector<char>& getNodes(){
        return nodes;
    }
};

GraphMatrix::GraphMatrix(GraphList &G){
    nodes = G.getNodes();
    nodesNum = nodes.size();
    edgsNum = 0;
    weights.resize(nodesNum, vector<int>(nodesNum));
    for(auto &row : weights){
        for(auto &it : row){
            it = INF;
        }
    }
    int count = 0;
    for(auto it : G.getEdges()){
        auto Edg = it->next;
        while(Edg){
            weights[count][Edg->val] = Edg->weight;
            Edg = Edg->next;
            ++edgsNum;
        }
        ++count;
    }
}
