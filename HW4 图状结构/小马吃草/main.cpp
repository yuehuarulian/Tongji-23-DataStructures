#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INT_MAXI 0x3f3f3f3f
using namespace std;
class Graph {
private:
    //链式前向星
    struct Edge {
        int to, weight, nxt;
        Edge(int t, int w, int n) : to(t), weight(w), nxt(n) {}
    };
    void Addedge(int u, int to, int w)//起点终点权值
    {
        Edge edge(to, w, head[u].first);
        //bool b = 0;
        ////只留下最小w的边
        //for (int i = head[u].first; i != -1;i=edges[i].nxt) {
        //    if (edges[i].to == to && edges[i].weight > w) {
        //        edges[i].weight = w;
        //        b = 1;
        //    }
        //}
        //if (!b) {
            head[u].first = ncnt++;
            edges.push_back(edge);
        //}
    }
    // brief 生成以root为根的源点到各点的最短路径
    void generateTree(int root) {
        vector<bool> vis;
        vis.resize(vexnum, 0);
        // 获取对应根节点的最短路径信息引用
        vector<int>& md = min_distance[root];
        md.resize(vexnum, INT_MAXI);
        md[root] = 0;
        // 定义比较结构体，用于构建最小堆每次弹出最小的树
        struct COMP {
            bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
                return p1.first > p2.first;
            }
        };
        // 优先队列，存储节点到根的距离和节点编号的pair，按距离从小到大排序
        priority_queue<pair<int, int>, vector<pair<int, int>>, COMP> pque;
        // 将根节点加入优先队列
        pque.push(std::make_pair(md[root], root));
        while (!pque.empty()) {
            int u = pque.top().second;
            pque.pop();
            if (vis[u])
                continue;
            vis[u] = 1;
            for (int i = head[u].first; i != -1; i = edges[i].nxt) {
                int to = edges[i].to;
                int w = edges[i].weight;
                if (md[to] > md[u] + w) {
                    md[to] = md[u] + w;
                    pque.push(make_pair(md[to], to));
                }
            }
        }
    }

    int ncnt;
    int horse_num;
    std::vector<Edge> edges;
    std::vector<pair<int,bool>>head;//记录head为起点上一条终点的编号 记录是否有牧草
    std::vector<vector<int>> min_distance;
    int vexnum, arcnum;//点的数量和边的数量
public:
    void scanf_and_print() 
    {
        cin >> vexnum >> arcnum;
        min_distance.resize(vexnum);
        for (int i = 0; i < vexnum; i++) {
            head.push_back(make_pair(-1, false));
        }
        ncnt = 0;
        for (int i = 0; i < arcnum; i++) {
            int u, to, w;
            cin >> u >> to >> w;
            Addedge(u - 1, to - 1, w);
            Addedge(to - 1, u - 1, w);//双向边
        }
        int H;
        cin >> H >> horse_num;
        //牧草
        for (int i = 0; i < H; i++) {
            int j;
            cin >> j;
            head[j - 1].second = true;
        }
        
        for (int i = 0; i < horse_num; i++) {
            int start, end;
            cin >> start >> end;
            if (!min_distance[start - 1].size())
                generateTree(start - 1);
            if (!min_distance[end - 1].size())
                generateTree(end - 1);
            int min_dis = INT_MAXI;
            for (int j = 0; j < vexnum; j++) {
                if (head[j].second == false)
                    continue;
                if (min_distance[start - 1][j] + min_distance[end - 1][j] < min_dis)
                    min_dis = min_distance[start - 1][j] + min_distance[end - 1][j];
            }
            cout << min_dis << endl;
        }
    }
};

int main() {
    Graph graph;
    graph.scanf_and_print();
}
