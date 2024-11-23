#include <iostream>
#include <stack>
using namespace std;
int main()
{
    string s;
    cin >> s;
    stack<int> STACK;
    int max_cn = 0;
    int qs = 0;
    if (s.size() == 1 || s.size() == 0){
        cout << 0 << " " << 0;
        return 0;
    }
    STACK.push(-1);
    for (int i = 0; s[i]; ++i) {
        if (s[i] == '(')
            STACK.push(i);
        else{
            STACK.pop();
            if (STACK.empty())
                STACK.push(i);//i是计数开始的前一个
            else if (i - STACK.top() > max_cn) {
                max_cn = i - STACK.top();//每次和单下来的（比较，如果距离大于max_cn就更新
                qs = STACK.top() + 1;
            }
        }
    }
    cout << max_cn << " " << qs << endl;
 /*   for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ')')/// (((())
            continue;
        for (int j = i; j < s.size(); j++) {
            if (s[j] == '(')
                STACK.push('(');
            else if (s[j] == ')' && !STACK.empty())
                STACK.pop();
            else if (s[j] == ')' && STACK.empty())
                break;
            if (STACK.empty() && (j - i + 1) > max_cn)
            {
                max_cn = j - i + 1;
                qs = i;
            }
        }
        while (!STACK.empty())
            STACK.pop();
    }*/
    return 0;
}