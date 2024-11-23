#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <cstring>
#include <string>
#define zhen 1
#define jia 0
#define fuha 2
#define error -1
using namespace std;
string s;
const char fh_label[5] = { '!','&','|','(',')' };
//返回优先级的比较结果   true:入栈  false:出栈和计算
bool uxj(char a, char b) 
{
    int A = 0, B = 0;
    while (A < 5 && fh_label[A] != a)
        A++;
    while (B < 5 && fh_label[B] != b)
        B++;
    return A > B;
}
//进行计算
void js(char fh, stack<bool>& bl_stack)
{
    bool a = 0, b = 0;
    if (fh == '!'){
        a = !bl_stack.top();
        bl_stack.pop();
        bl_stack.push(a);
    }
    else if (fh == '&'){
        a = bl_stack.top();
        bl_stack.pop();
        b = bl_stack.top();
        bl_stack.pop();
        bl_stack.push(a & b);
    }
    else if (fh == '|')
    {
        a = bl_stack.top();
        bl_stack.pop();
        b = bl_stack.top();
        bl_stack.pop();
        bl_stack.push(a | b);
    }
    return;
}
//判断char a是符号，bool值还是空格
int judge(char a)
{
    if (a == 'V')
        return zhen;
    else if (a == 'F')
        return jia;
    else if (a == '!' || a == '&' || a == '|' || a == '(' || a == ')')
        return fuha;
    else
        return error;
}
int main()
{
    string s;
    int cn = 1;
    stack<char>fh_stack;//符号栈
    stack<bool>bl_stack;//bool值栈
    while (getline(cin, s)) {
        int a = 0;//记录仪!!的个数
        //遍历s，符号和bool值依次入栈
        for (int i = 0; i < s.size(); i++) {
            int p = judge(s[i]);
            if (p == error)
                continue;
            //处理bool值
            if (p != fuha) {
                bl_stack.push(p);
                continue;
            }
            //处理!!
            if (s[i] == '!')
                a++;
            else
                a = 0;
            if (a == 2) {
                a = 0;
                fh_stack.pop();
                continue;
            }
            //处理符号
            if (fh_stack.empty() || s[i] == '(') // ( 或栈为空直接进栈
            {
                fh_stack.push(s[i]);
                continue;
            }
            else if (s[i] == ')') {                   // 右括号，括号里先算
                while (fh_stack.top() != '(') {
                    js(fh_stack.top(), bl_stack);//计算
                    fh_stack.pop();
                }
                fh_stack.pop();
                continue;
            }
            else if (!fh_stack.empty() && !uxj(fh_stack.top(), s[i])) {//优先级s[i]<=fh_stack.top,运算
                while (!fh_stack.empty() && !uxj(fh_stack.top(), s[i])) {
                    js(fh_stack.top(), bl_stack);//计算
                    fh_stack.pop();
                }
                fh_stack.push(s[i]);
                continue;
            }
            else
                fh_stack.push(s[i]);
        }
        //计算栈里剩余的符号和bool值
        while (!fh_stack.empty()) {
            js(fh_stack.top(), bl_stack);
            fh_stack.pop();
        }
        //输出
        if (bl_stack.top() == zhen)
            cout << "Expression " << cn << ": " << 'V' << endl;
        else
            cout << "Expression " << cn << ": " << 'F' << endl;
        cn++;
        bl_stack.pop();
    }
    return 0;
}

