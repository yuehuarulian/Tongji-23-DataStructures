#include <iostream>
#include <string>
#include <stack>
using namespace std;
int error = 0;
string fout;
void getPostOrder(string inorder, string preorder) {
    if (inorder.empty() || error == 1) {
        return;
    }
    int rootIndex = inorder.find(preorder[0]);//找到第一个的位置
    if (rootIndex == string::npos)
    {
        error = 1;
        return;
    }
    string leftInorder = inorder.substr(0, rootIndex);
    string rightInorder = inorder.substr(rootIndex + 1);
    string leftPreorder = preorder.substr(1, rootIndex);
    string rightPreorder = preorder.substr(1 + rootIndex);

    getPostOrder(leftInorder, leftPreorder);
    getPostOrder(rightInorder, rightPreorder);
    fout += preorder[0];
    //cout << preorder[0];
}

int main() {
    string inorder, preorder;
    while (1) {
        error = 0;
        fout = "";
        cin >> preorder >> inorder;
        if (cin.eof())
            break;
        /*if (preorder.size()==0 && inorder.size()==0)
            break;*/
        if (preorder.size() != inorder.size())
        {
            cout << "Error" << endl;
            continue;
        }
        getPostOrder(inorder, preorder);
        if (error == 1)
        {
            fout = "Error";
        }
        cout << fout << endl;
    }
    return 0;
}