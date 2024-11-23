#include <iostream>
#include <string>
#include <stack>
using namespace std;

void getPostOrder(string inorder, string preorder) {
    if (inorder.empty()) {
        return;
    }

    int rootIndex = inorder.find(preorder[0]);//找到第一个的位置
    if (rootIndex == string::npos)
        exit;
    string leftInorder = inorder.substr(0, rootIndex);
    string rightInorder = inorder.substr(rootIndex + 1);
    string leftPreorder = preorder.substr(1, rootIndex);
    string rightPreorder = preorder.substr(1 + rootIndex);

    getPostOrder(leftInorder, leftPreorder);
    getPostOrder(rightInorder, rightPreorder);

    cout << preorder[0];
}

int main() {
    int n;
    stack <char> Stack;
    cin >> n;
    string inorder, preorder;
    while (inorder.size() < n || preorder.size() < n) {
        string c;
        cin >> c;
        if (c == "push") {
            char z;
            cin >> z;
            Stack.push(z);
            preorder += z;
        }
        else if (c == "pop") {
            inorder += Stack.top();
            Stack.pop();
        }
        else
            break;
    }

    getPostOrder(inorder, preorder);
    cout << endl;

    return 0;
}