#include <iostream>
#include <stack>
using namespace std;
string train, dst;
// ��Ҫ���ܺ������ж��Ƿ����ͨ��������ʽ�ӳ��ڳ���
// ���룺train - ��վ���У�dst - ��վ����
// �����������Եõ������ "yes"��������� "no"
int main()
{
    cin >> train;           //train��������ʼ�ݷ�˳��
    int top = 0;
    while ((cin >> dst))    //dst������Ŀ���վ˳��
    {
        stack<char> STACK;  //��ʾ��վ��LIFO
        top = 0;            //ָ��Ŀ����ɵ�λ��
        for (int i = 0; i < train.size() && top <= dst.size(); i++) {
            // �������Ƚϣ����ƥ�����ƶ�λ��
            if (train[i] == dst[top]) {
                top++;
                continue;
            }
            // ���ջ������ƥ�䣬���ջ
            if (!STACK.empty() && STACK.top() == dst[top]) {
                STACK.pop();
                top++;
                i--; // û�д�����һ�����Σ��������֮ǰ�Ž�ȥ��
            }
            else
                STACK.push(train[i]); // �����ƥ�䣬��ջ
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