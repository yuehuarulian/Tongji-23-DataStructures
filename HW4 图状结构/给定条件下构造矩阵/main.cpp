#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#define MAX_NUM 450
typedef struct MGraph {
    int vexs[MAX_NUM] = { 0 };//�ڵ�
    std::vector<std::vector<int>> arcs; // �ڽӾ���
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
        //���������
        for (int i = 0; i < G.arcnum; i++) {
            int abovei, belowi;
            std::cin >> abovei >> belowi;
            if (!G.arcs[abovei - 1][belowi - 1]) {
                G.arcs[abovei - 1][belowi - 1] = 1;//�����
                G.indegree[belowi - 1]++;//�������
            }
        }
        //�ҵ����Ϊ0�ĵ�
        int top = -1;
        for (int i = 0; i < G.vexnum; i++) {
            if (G.indegree[i] == 0) {
                G.indegree[i] = top;//-1
                top = i;//��ջ
            }
        }
        int count = 0;
        while (top != -1) {
            int i = top;//ָ��ǰ��ջ�Ľڵ�
            top = G.indegree[top];//��ջ
            if (type == col_)
                col_order.push_back(i);//��¼��������˳��
            else
                row_order.push_back(i);
            count++;
            //ɨ��ýڵ�ĳ��߱�
            for (int j = 0; j < G.vexnum; j++) {
                if (G.arcs[i][j] == 1) {
                    G.indegree[j]--;//������ȼ�һ
                    if (G.indegree[j] == 0) {//������Ϊ����ջ
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
    std::vector<int>col_order;//�����˳��
    std::vector<int>row_order;//�����˳��
    int MATRIX_DIM;
    int COL, ROW;
};
int main()
{
    int dimension, col, row;
    std::cin >> dimension >> row >> col;//�������
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