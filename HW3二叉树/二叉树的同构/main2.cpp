#include <iostream>
#include <string>
#include <stack>
using namespace std;

typedef struct Node {
	char c;
	int lchild;
	int rchild;
	int parent;
	void init()
	{
		c = '\0';
		lchild = -1;
		rchild = -1;
		parent = -1;
	}
}Tree;


void f_in(Tree tree[], int& root, int& n)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		tree[i].init();
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> tree[i].c;
		cin >> t;
		//��������
		if (cin.good())
		{
			tree[i].lchild = t;
			tree[t].parent = i; //parent�ڵ��¼Ϊi
		}
		else //������Ϊ'-'��ʱ��ͻ�������󣬼�Ϊ0
			cin.clear();
		cin >> t;
		//�����Һ���
		if (cin.good())
		{
			tree[i].rchild = t;
			tree[t].parent = i; //parent�ڵ��¼Ϊi
		}
		else //������Ϊ'-'��ʱ��ͻ�������󣬼�Ϊ��
			cin.clear();
	}
	//û��parent�Ľڵ���Ǹ��ڵ�
	for (int i = 0; i < n; i++)
	{
		if (tree[i].parent == -1)
		{
			root = i;
			break;
		}
	}
}
int Depth(const int i, const Tree tree[])
{
	int deepl = 0, deepr = 0;
	if (tree[i].c) {
		if (tree[i].lchild != -1)
			deepl = Depth(tree[i].lchild, tree);
		if (tree[i].rchild != -1)
			deepr = Depth(tree[i].rchild, tree);
		return max(deepl, deepr) + 1;
	}
	return 0;
}

bool judge(int i1, int i2, Tree tree1[], Tree tree2[])
{
	if (i1 == -1 && i2 == -1)
		return true;
	if (i1 == -1 || i2 == -1)
		return false;
	if (tree1[i1].c && tree2[i2].c && tree1[i1].c == tree2[i2].c) {
		if (judge(tree1[i1].lchild, tree2[i2].lchild, tree1, tree2) && judge(tree1[i1].rchild, tree2[i2].rchild, tree1, tree2))
			return true;
		else if (judge(tree1[i1].lchild, tree2[i2].rchild, tree1, tree2) && judge(tree1[i1].rchild, tree2[i2].lchild, tree1, tree2))
			return true;
	}
	return false;
}
int main()
{
	//����
	int n1, n2;
	Tree tree1[10200];
	Tree tree2[10200];
	int root1, root2;
	f_in(tree1, root1,n1);
	f_in(tree2, root2,n2);
	//���������
	int size1 = Depth(root1, tree1);
	int size2 = Depth(root2, tree2);
	//�Ƿ�ͬ��
	if (size1 != size2) 
		cout << "No" << endl;
	else if (judge(root1, root2,tree1,tree2)) 
		cout << "Yes" << endl;
	else 
		cout << "No" << endl;
	//������
	cout << size1 << endl;
	cout << size2 << endl;
	return 0;
}

