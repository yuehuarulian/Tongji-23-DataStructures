#include <iostream>
#include <string>
using namespace std;
typedef struct Node {
    int parent = -1;//parent编号
    int data = 1;//这一层的第几个孩子
}Tree;
Tree TREE[2000000];
int main()
{
    string s;
    int longest_tree, longest_twotree;
    int longest_tree_tem, longest_twotree_tem;
    int cou = 0;
    while (1) {
        cin >> s;
        if (s == "#")
            break;
        cou++;
        longest_tree = 0;
        longest_twotree = 0;
        longest_tree_tem = 0;
        longest_twotree_tem = 0;
        int Size = s.size();
        int p = 0;//永远指向当下节点位置
        int tree_num = 0;//这一节点的位置
        for (int i = 0; i < Size; i++) {
            if (s[i] == 'd') {
                tree_num++;//
                TREE[tree_num].parent = p;//
                TREE[tree_num].data = 1;
                p = tree_num;
                longest_tree_tem++;
                longest_tree = max(longest_tree, longest_tree_tem);
            }
            else {//s[i]=='u'
                p = TREE[p].parent;
                longest_tree_tem--;
            }
        }
        //dudduduudu
        p = 0;
        tree_num = 0;
        for (int i = 0; i < Size; i++) {
            if (s[i] == 'd') {
                tree_num++;//
                p = tree_num;//
                longest_twotree_tem++;
                longest_twotree = max(longest_twotree, longest_twotree_tem);
            }
            else {//s[i]=='u'
                if (i + 1 < Size && s[i + 1] == 'd') {
                    tree_num++;//
                    TREE[tree_num].data = TREE[p].data + 1;//
                    p = tree_num;//

                    longest_twotree_tem++;
                    longest_twotree = max(longest_twotree, longest_twotree_tem);
                    i++;
                }
                else {
                    longest_twotree_tem -= TREE[p].data;
                    p = TREE[p].parent;//
                }
            }
        }
        //cout << longest_tree_tem << endl;
        cout << "Tree " << cou << ": " << longest_tree << " => " << longest_twotree << endl;//Tree 1: 2 => 4
    }
}