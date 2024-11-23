#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iomanip>
#define MAX_NUM 2000
#define MAX_depth 6
typedef struct NODE {
    int id, count;//count:��֮���벻����6�ĸ���
    std::vector<int> next;//��֮���ڵĽڵ�
    NODE(int i) : id(i) ,count(0){}
}NODE;
class Picture {
public:
    void CreateMGraph()
    {
        std::cin >> vexnum >> arcnum;
        //���ɽڵ��һ������
        for (int i = 0; i <= vexnum; i++) {
            list.push_back(NODE(i));
        }
        //�ű�
        for (int i = 0; i < arcnum; i++) {
            int y, x;
            std::cin >> y >> x;
            list[y].next.push_back(x);
            list[x].next.push_back(y);
        }
        for (int i = 1; i <= vexnum; i++) {
            std::sort(list[i].next.begin(), list[i].next.end());
        }
    }
    void soluteBFS()
    {
      /*  for (auto& node : list) {
            bool chart[2000] = { 0 };
            chart[node.id] = true;
            std::queue<std::pair<int, int>> que;
            que.push(std::make_pair(0, node.id));
            while (!que.empty()) {
                node.count++;
                int count = que.front().first;
                NODE& n = list[que.front().second];
                que.pop();
                for (auto next : n.next) {
                    if (!chart[next]) {
                        chart[next] = true;
                        if (count < 6)
                            que.push(std::make_pair(count + 1, next));
                    }
                }
            }
        }*/

        for (auto &node : list) {
            if (node.id == 0)
                continue;
            bool visited[MAX_NUM] = { 0 };
            std::queue<std::pair<int,int>> que;
            que.push(std::make_pair(0, node.id));
            visited[node.id] = 1;
            while (!que.empty()) {
                int depth = que.front().first;//��¼����
                NODE& now = list[que.front().second];
                que.pop();
                if (++depth > MAX_depth)
                    break;
                //���ڽڵ���que
                for (auto next_id:now.next) {
                    if ( !visited[next_id]) {
                        visited[next_id] = 1;
                        que.push(std::make_pair(depth, next_id));
                        node.count++;//���һ��˵����֮����С��MAX_depth����Ŀ��һ��
                    }
                }

            }
        }
    }
   /* 1: 70.00 %
        2 : 80.00 %
        3 : 90.00 %*/
    void F_OUT()
    {
        for (int i = 1; i <= vexnum; i++) {
            std::cout << i << ": " << std::fixed << std::setprecision(2) << round(++list[i].count * 10000.0 / vexnum) / 100.0 << "%" << std::endl;
        }
    }
private:
    int vexnum, arcnum;
    std::vector<NODE> list;
};

int main()
{
    Picture pic;
    pic.CreateMGraph();
    pic.soluteBFS();
    pic.F_OUT();
    return 0;
}