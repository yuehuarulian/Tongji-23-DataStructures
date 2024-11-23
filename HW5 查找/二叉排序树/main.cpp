#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int n;
typedef struct BiTNode {
    int data;
    int cou;//�ж��ٸ�
    int lchild, rchild;
    int parent;
    BiTNode(int d = NULL, int c = 1, int l = -1, int r = -1, int p = -1) :data(d), cou(c), lchild(l), rchild(r), parent(p) {};
}BiTNode;
vector<BiTNode>BiTree;
/*
��op=1���������һ������x����ʾ��������x
��op=2���������һ������x����ʾɾ������x����������ɾ�����������None�����ж����ֻɾ��һ������
��op=3���������һ������x���������x�ڼ������ж��ٸ�����x���ڼ����������0��
��op=4����������е���Сֵ����֤���Ϸǿգ�
��op=5���������һ������x�����x��ǰ������������ǰ�������None��x��һ���ڼ����У�
*/
void insert(int x)
{
    if (BiTree.empty()) {
        BiTNode node(x);
        BiTree.push_back(node);
        return;
    }
    int p = 0, q = p;
    while (p != -1) {
        q = p;
        if (x < BiTree[p].data)
            p = BiTree[p].lchild;
        else if (x == BiTree[p].data) {//����˾ͼ�һ��
            BiTree[p].cou++;
            return;
        }
        else
            p = BiTree[p].rchild;
    }
    //��Ҷ�ӽڵ��
    BiTNode node(x, 1, -1, -1, q);
    BiTree.push_back(node);
    if (x < BiTree[q].data)
        BiTree[q].lchild = int(BiTree.size()) - 1;
    else
        BiTree[q].rchild = int(BiTree.size()) - 1;
}
bool Delete(int nodenum)
{
    int p = nodenum;
    if (--BiTree[p].cou)//����ڵ�ɾ��һ��
        return true;
    int q = BiTree[p].parent;
    if (q == -1)//???
        BiTree.clear();
    if (BiTree[p].rchild == -1) {//������Ϊ��
        if (BiTree[q].lchild == p) {
            BiTree[q].lchild = BiTree[p].lchild;
        }
        else {
            BiTree[q].rchild = BiTree[p].lchild;
        }
    }
    else if (BiTree[p].lchild == -1) {//������Ϊ��
        if (BiTree[q].lchild == p) {
            BiTree[q].lchild = BiTree[p].rchild;
        }
        else {
            BiTree[q].rchild = BiTree[p].rchild;
        }
    }
    else {//������������Ϊ��
        int s = BiTree[p].lchild;
        while (BiTree[s].rchild != -1) {//���Ҳ�Ԫ��
            s = BiTree[s].rchild;
        }
        BiTree[p].data = BiTree[s].data;
        BiTree[p].cou = BiTree[s].cou;
        if (BiTree[s].parent != p) {
            BiTree[BiTree[s].parent].rchild = BiTree[s].lchild;
        }
        else {
            BiTree[p].lchild = BiTree[s].lchild;
        }
    }
    return true;
}
bool deleteItem(int x, int nodenum)
{
    if (nodenum == -1 || BiTree.empty())//���ڷ�Χ�ڰ���-1�Ϳ�״̬
        return false;
    else if (x == BiTree[nodenum].data)
        return Delete(nodenum);
    else if (x < BiTree[nodenum].data)
        return deleteItem(x, BiTree[nodenum].lchild);
    else
        return deleteItem(x, BiTree[nodenum].rchild);
}
int counter(int x, int nodenum)
{
    if (nodenum == -1 || BiTree.empty())//���ڷ�Χ�ڰ���-1�Ϳ�״̬
        return 0;
    if (x == BiTree[nodenum].data)
        return BiTree[nodenum].cou;
    else if (x < BiTree[nodenum].data)
        return counter(x, BiTree[nodenum].lchild);
    else //(x > BiTree[nodenum].data)
        return counter(x, BiTree[nodenum].rchild);
}
int finderMin()
{
    if (BiTree.empty())
        return -1;
    int p = 0;
    while (BiTree[p].lchild != -1)
        p = BiTree[p].lchild;
    return BiTree[p].data;
}
int finderPre(int x, int now)
{
    if (BiTree.empty())
        return -1;
    if (now == -1)
        return -1000000;
    if (x <= BiTree[now].data)
        return finderPre(x, BiTree[now].lchild);
    else// if (x > BiTree[now].data)
        return max(BiTree[now].data, finderPre(x, BiTree[now].rchild));

}
int main()
{
    int n;
    int option = 0, element = 0;
    int last = 0;
    cin >> n;
    BiTNode node(200404);
    BiTree.push_back(node);
    for (int i = 0; i < n; i++)
    {
        cin >> option;
        switch (option)
        {
            case 1:
                cin >> element;
                insert(element);//��������x
                break;
            case 2:
                cin >> element;
                if (!deleteItem(element, 0))//ɾ������x
                    cout << "None" << endl;
                break;
            case 3:
                cin >> element;
                cout << counter(element, 0) << endl;//�������x�ڼ������ж��ٸ�����x���ڼ����������0��
                break;
            case 4:
                cout << finderMin() << endl;//��������е���Сֵ����֤���Ϸǿգ�
                break;
            case 5:
                cin >> element;
                if (BiTree.empty() || element <= finderMin())
                    cout << "None" << endl;
                else
                    cout << finderPre(element, 0) << endl;//���x��ǰ������������ǰ�������None��x��һ���ڼ����У�
                break;
            default:
                break;
        }
    }
    return 0;
}

/*

12
1 32
1 12
1 85
1 12
2 0
1 1
1 10
1 12
3 12
4
5 12
5 30
��op=1���������һ������x����ʾ��������x
��op=2���������һ������x����ʾɾ������x����������ɾ�����������None�����ж����ֻɾ��һ������
��op=3���������һ������x���������x�ڼ������ж��ٸ�����x���ڼ����������0��
��op=4����������е���Сֵ����֤���Ϸǿգ�
��op=5���������һ������x�����x��ǰ������������ǰ�������None��x��һ���ڼ����У�

*/