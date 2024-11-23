#include <iostream>
#include <deque>
#include <string>
using namespace std;
/*（1）Enqueue(v): v 入队

（2）Dequeue(): 使队首元素删除，并返回此元素

（3）GetMax(): 返回队列中的最大元素*/
class DEQUE {
private:
	deque<int>q;
	deque<int>max_q;
    int n;
public:
    DEQUE(int len)
    {
        n = len;
    }
	void Enqueue(int value);
	void Dequeue();
	void GetMax();
    void Quit();
};

void DEQUE::Enqueue(int value)
{
    if (q.size() == n) {
        cout << "Queue is Full" << endl;
        return;
    }
    else {
        q.push_back(value);
        while (!max_q.empty() && max_q.back() < value)
            max_q.pop_back();
        max_q.push_back(value);
    }
}
void DEQUE::Dequeue()
{
    if (q.empty()) {
        cout << "Queue is Empty" << endl;
        return;
    }
    int value = q.front();
    q.pop_front();
    if (value == max_q.front())
        max_q.pop_front();
    cout << value << endl;
}
void DEQUE::GetMax()
{
    if (q.empty()){
        cout << "Queue is Empty" << endl;
        return;
    }
    cout << max_q.front() << endl;
}
void DEQUE::Quit()
{
    while (!q.empty()) {
        cout << q.front() << ' ';
        q.pop_front();
    }
}
int main()
{
    int num = 0;
    cin >> num;
    DEQUE a(num);
    string s;
    while (1) {
        cin >> s;
        if (s == "enqueue") {
            int m;
            cin >> m;
            a.Enqueue(m);
        }
        else if (s == "dequeue") {
            a.Dequeue();
        }
        else if (s == "max") {
            a.GetMax();
        }
        else if (s == "quit") {
            a.Quit();
            break;
        }
    }
    return 0;

}

