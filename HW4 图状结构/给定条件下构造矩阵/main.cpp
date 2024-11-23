#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#define MAX_NUM 450
typedef struct MGraph {
    int vexs[MAX_NUM] = { 0 };//节点
    std::vector<std::vector<int>> arcs; // 邻接矩阵
    std::vector<int>indegree;
    int vexnum, arcnum;
    MGraph() : arcs(MAX_NUM, std::vector<int>(MAX_NUM, 0)), indegree(MAX_NUM, 0) {}
}MGraph;

class Picture {
public:
    enum ORDER_TYPE { col_, row_ };
    Picture(int dimension, int r, int c) :MATRIX_DIM(dimension), ROW(r), COL(c) {}
    bool ToplogicalSort(ORDER_TYPE type)
    {
        MGraph G;
        G.vexnum = MATRIX_DIM;
        if (type == col_)
            G.arcnum = COL;
        else
            G.arcnum = ROW;
        //输入有向边
        for (int i = 0; i < G.arcnum; i++) {
            int abovei, belowi;
            std::cin >> abovei >> belowi;
            if (!G.arcs[abovei - 1][belowi - 1]) {
                G.arcs[abovei - 1][belowi - 1] = 1;//有向边
                G.indegree[belowi - 1]++;//计算入度
            }
        }
        //找到入度为0的点
        int top = -1;
        for (int i = 0; i < G.vexnum; i++) {
            if (G.indegree[i] == 0) {
                G.indegree[i] = top;//-1
                top = i;//入栈
            }
        }
        int count = 0;
        while (top != -1) {
            int i = top;//指向当前出栈的节点
            top = G.indegree[top];//出栈
            if (type == col_)
                col_order.push_back(i);//记录拓扑排序顺序
            else
                row_order.push_back(i);
            count++;
            //扫描该节点的出边表
            for (int j = 0; j < G.vexnum; j++) {
                if (G.arcs[i][j] == 1) {
                    G.indegree[j]--;//顶点入度减一
                    if (G.indegree[j] == 0) {//如果入度为零入栈
                        G.indegree[j] = top;
                        top = j;
                    }
                }
            }
        }
        if (count < G.vexnum)
            return false;
        else
            return true;
    }
    void PRINT_MATRIX()
    {
        for (int i = 0; i < MATRIX_DIM; i++) {
            for (int j = 0; j < MATRIX_DIM; j++) {
                if (row_order[i] == col_order[j])
                    std::cout << row_order[i] + 1 << ' ';
                else
                    std::cout << 0 << ' ';
            }
            std::cout << std::endl;
        }
    }
private:
    std::vector<int>col_order;//存放列顺序
    std::vector<int>row_order;//存放行顺序
    int MATRIX_DIM;
    int COL, ROW;
};
int main()
{
    int dimension, col, row;
    std::cin >> dimension >> row >> col;//矩阵阶数
    Picture pic(dimension, row, col);
    if (!pic.ToplogicalSort(Picture::row_)) {
        std::cout << -1 << std::endl;
        return 0;
    }
    if (!pic.ToplogicalSort(Picture::col_)) {
        std::cout << -1 << std::endl;
        return 0;
    }
    pic.PRINT_MATRIX();
    return 0;
}