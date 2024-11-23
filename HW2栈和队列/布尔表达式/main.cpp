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
//�������ȼ��ıȽϽ��   true:��ջ  false:��ջ�ͼ���
bool uxj(char a, char b) 
{
    int A = 0, B = 0;
    while (A < 5 && fh_label[A] != a)
        A++;
    while (B < 5 && fh_label[B] != b)
        B++;
    return A > B;
}
//���м���
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
//�ж�char a�Ƿ��ţ�boolֵ���ǿո�
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
    stack<char>fh_stack;//����ջ
    stack<bool>bl_stack;//boolֵջ
    while (getline(cin, s)) {
        int a = 0;//��¼��!!�ĸ���
        //����s�����ź�boolֵ������ջ
        for (int i = 0; i < s.size(); i++) {
            int p = judge(s[i]);
            if (p == error)
                continue;
            //����boolֵ
            if (p != fuha) {
                bl_stack.push(p);
                continue;
            }
            //����!!
            if (s[i] == '!')
                a++;
            else
                a = 0;
            if (a == 2) {
                a = 0;
                fh_stack.pop();
                continue;
            }
            //�������
            if (fh_stack.empty() || s[i] == '(') // ( ��ջΪ��ֱ�ӽ�ջ
            {
                fh_stack.push(s[i]);
                continue;
            }
            else if (s[i] == ')') {                   // �����ţ�����������
                while (fh_stack.top() != '(') {
                    js(fh_stack.top(), bl_stack);//����
                    fh_stack.pop();
                }
                fh_stack.pop();
                continue;
            }
            else if (!fh_stack.empty() && !uxj(fh_stack.top(), s[i])) {//���ȼ�s[i]<=fh_stack.top,����
                while (!fh_stack.empty() && !uxj(fh_stack.top(), s[i])) {
                    js(fh_stack.top(), bl_stack);//����
                    fh_stack.pop();
                }
                fh_stack.push(s[i]);
                continue;
            }
            else
                fh_stack.push(s[i]);
        }
        //����ջ��ʣ��ķ��ź�boolֵ
        while (!fh_stack.empty()) {
            js(fh_stack.top(), bl_stack);
            fh_stack.pop();
        }
        //���
        if (bl_stack.top() == zhen)
            cout << "Expression " << cn << ": " << 'V' << endl;
        else
            cout << "Expression " << cn << ": " << 'F' << endl;
        cn++;
        bl_stack.pop();
    }
    return 0;
}

