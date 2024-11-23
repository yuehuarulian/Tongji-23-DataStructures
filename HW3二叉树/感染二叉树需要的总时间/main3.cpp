#include <iostream>
#include <string>
#include <queue>
using namespace std;

typedef struct Node {
	int lchild;
	int rchild;
	int parent;
	int num;
	void init()
	{
		parent = -1;
		lchild = -1;
		rchild = -1;
		num = -1;
	}
}Tree;


void f_in(Tree tree[], const int n)
{
	for (int i = 0; i < n; i++)
		tree[i].init();
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		//读入左孩子
		tree[i].lchild = t;
		if (t != -1)
			tree[t].parent = i; //parent节点记录为i
		cin >> t;
		//读入右孩子
		tree[i].rchild = t;
		if (t != -1)
			tree[t].parent = i; //parent节点记录为i
		tree[i].num = i;
	}
}
//void dfs(int index, Tree tree[], int start, int& to_start, int& longest)
//{
//	if (index == -1) {
//		to_start = -1;
//		longest = 0;
//	}
//	int l_to_start = -1, l_longest = 0, r_to_start = -1, r_longest = 0;
//	if (tree[index].lchild != -1) {
//		dfs(tree[index].lchild,tree, start, l_to_start, l_longest);
//	}
//	if (tree[index].rchild != -1) {
//		dfs(tree[index].rchild,tree, start, r_to_start, r_longest);
//	}
//
//	if (start == index) {
//		to_start = 1;
//		longest = std::max(l_longest, r_longest);
//	}
//	else if (l_to_start != -1) {
//		to_start = l_to_start + 1;
//		longest = std::max(l_longest, l_to_start + r_longest);
//	}
//	else if (r_to_start != -1) {
//		to_start = r_to_start + 1;
//		longest = std::max(r_longest, r_to_start + l_longest);
//	}
//	else {
//		to_start = -1;
//		longest = std::max(l_longest, r_longest) + 1;
//	}
//}
 
int d[100100];
queue <Node>que;
int dfs(const int index, const Tree tree[], const int n)
{
    //把所有的位置都初始化为INF
	for (int i = 0; i < n; i++)
		d[i] = -1;
	//将start加入队列，并把这一地点的距离设置为0
    que.push(tree[index]);
    d[index] = 0;
    //不断循环直到队列的长度为0
    while (que.size())
    {
        //从队列的最前端取出元素
        Node p = que.front();
        que.pop();

        //三个方向的循环
		//左子树
		if (p.lchild != -1 && d[p.lchild] == -1) {//有左子树且左子树没有被遍历到
			que.push(tree[p.lchild]);
			d[p.lchild] = d[p.num] + 1;
		}
		if (p.rchild != -1 && d[p.rchild] == -1) {//有右子树且右子树没有被遍历到
			que.push(tree[p.rchild]);
			d[p.rchild] = d[p.num] + 1;
		}
		if (p.parent != -1 && d[p.parent] == -1) {//有parent树且parent树没有被遍历到
			que.push(tree[p.parent]);
			d[p.parent] = d[p.num] + 1;
		}
    }
	int longest = 0;
	for (int i = 0; i < n; i++) {
		if (d[i] > longest)
			longest = d[i];
	}
    return longest;
}
Tree tree[100100];
int main()
{
	int n, start;
	cin >> n >> start;
	f_in(tree, n);
	int longest = dfs(start, tree, n);
	cout << longest << endl;
	return 0;
}