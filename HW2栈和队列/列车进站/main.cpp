#include <iostream>
#include <stack>
using namespace std;
string train, dst;
// 主要功能函数，判断是否可以通过给定方式从出口出来
// 输入：train - 入站序列，dst - 出站序列
// 输出：如果可以得到，输出 "yes"，否则输出 "no"
int main()
{
    cin >> train;           //train：车的起始拜访顺序
    int top = 0;
    while ((cin >> dst))    //dst：车的目标出站顺序
    {
        stack<char> STACK;  //表示车站，LIFO
        top = 0;            //指向目标完成的位置
        for (int i = 0; i < train.size() && top <= dst.size(); i++) {
            // 逐个车厢比较，如果匹配则移动位置
            if (train[i] == dst[top]) {
                top++;
                continue;
            }
            // 如果栈顶车厢匹配，则出栈
            if (!STACK.empty() && STACK.top() == dst[top]) {
                STACK.pop();
                top++;
                i--; // 没有处理下一个车次，处理的是之前放进去的
            }
            else
                STACK.push(train[i]); // 如果不匹配，入栈
        }
        while (!STACK.empty() && top <= dst.size() && STACK.top() == dst[top]) {
            top++;
            STACK.pop();
        }
        if(STACK.empty())
            cout << "yes" << endl;
        else
            cout << "no" << endl;

    }
    return 0;
}