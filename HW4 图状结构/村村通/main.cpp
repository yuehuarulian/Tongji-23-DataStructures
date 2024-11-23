#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#define MAX_NUM 120
#define INF 10000
typedef struct MGraph {
    int vexs[MAX_NUM] = { 0 };//节点
    std::vector<std::vector<int>> arcs; // 邻接矩阵
    int vexnum, arcnum;
    MGraph() : arcs(MAX_NUM, std::vector<int>(MAX_NUM, 0)) {
        // 这里初始化 arcs 为 MAX_NUM x MAX_NUM 的零矩阵
    }
}MGraph;
typedef struct {
    int adjvex;
    int lowcost;
}Closedge;
class Picture {
public:
    void CreateMGraph()
    {
        std::cin >> G.vexnum;//村庄数目
        for (int i = 0; i < G.vexnum; i++) {
            G.vexs[i] = i + 1;
        }
        for (int i = 0; i < G.vexnum; i++) {//距离
            for (int j = 0; j < G.vexnum; j++) {
                std::cin >> G.arcs[i][j];
            }
        }
        std::cin >> G.arcnum;//相连的村庄
        for (int i = 0; i < G.arcnum; i++) {
            int y, x;
            std::cin >> y >> x;
            x--;
            y--;
            G.arcs[y][x] = 0;//相连距离为0
            G.arcs[x][y] = 0;
        }
        for (int i = 0; i < G.vexnum; i++) {
            std::vector<int>vec;
            for (int j = 0; j < G.vexnum; j++) {
                if (G.arcs[i][j] == 0) {
                    vec.push_back(j);
                }
            }
            if (vec.size() < 2)
                continue;
            MIN(vec);
        }
    }
    // 更新为所有相连的村庄中的最小距离
    void MIN(std::vector<int>& vec)
    {
        for(int j=0;j<G.vexnum;j++){
            int minCost = INF;
            for (int i : vec) {
                if (G.arcs[j][i] < minCost)
                    minCost = G.arcs[j][i];
            }
            for (int i : vec) {
                G.arcs[i][j] = G.arcs[j][i] = minCost;
            }
        }
    }
    // 计算最小距离，使用 Prim 算法
    void calculateMinDistance(int start = 0)
    {
        //初始化最小距离数组
        for (int j = 0; j < G.vexnum; j++) {
            closedge[j].adjvex = start;
            closedge[j].lowcost = G.arcs[j][start];
        }
        //找出最小边
        while (!judge()) {
            int minCost = INF;
            for (int j = 0; j < G.vexnum; j++) {
                if (closedge[j].lowcost < minCost && closedge[j].lowcost != 0) {
                    minCost = closedge[j].lowcost;
                    start = j;
                }
            }
            distance += minCost;
            for (int j = 0; j < G.vexnum; j++) {
                if (G.arcs[start][j] < closedge[j].lowcost)
                {
                    closedge[j].adjvex = start;
                    closedge[j].lowcost = G.arcs[start][j];
                }
            }
        }
    }
    int distance = 0;
    Closedge closedge[MAX_NUM];
private:
    //是否已经联通
    bool judge()
    {
        for (int i = 0; i < G.vexnum; i++) {
            if (closedge[i].lowcost)
                return false;
        }
        return true;
    }
    MGraph G;
};
int main()
{
    Picture pic;
    pic.CreateMGraph();
    pic.calculateMinDistance();
    std::cout << pic.distance << std::endl;
    return 0;
}