#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define INT_MAX       2147483647
class Graph {
private:
    struct Subject {
        int time_consuming;     // �ۼ�����ʱ��
        int last_subjects,next_subjects;   // ǰ����Ŀ�����ͺ�̿�Ŀ����
        // ��Ŀ��ʼ�����������ʱ��
        int min_start_time;//ve
        int max_start_time;//vl
        std::vector<int> next;   // ��̿�Ŀ�б�
        std::vector<int> last;   // ǰ����Ŀ�б�
        bool important;
        Subject() : last_subjects(0), next_subjects(0), min_start_time(0), max_start_time(INT_MAX), important(0) {}
    };

    int size;
    std::vector<Subject> subjects;
public:
    // ���캯�������ɾ���ָ�����������ͼ
    void f_in()
    {
        //��Ŀ����
        cin >> size;
        //64 3 2 3 5
        for (int i = 0; i < size; i++) {
            Subject subject;
            cin >> subject.time_consuming;//time
            cin >> subject.last_subjects;//ǰ������
            for (int j = 0; j < subject.last_subjects; j++) {
                int k;
                cin >> k;
                subject.last.push_back(k - 1);
            }
            subjects.push_back(subject);
        }
        //�ֶ���������¼�
        Subject subject;
        subject.time_consuming = 0;
        subject.next_subjects = 0;
        subjects.push_back(subject);
        //���next�Ŀγ�
        for (int i = 0; i < size; i++) {
            for (int j : subjects[i].last) {
                subjects[j].next.push_back(i);
                subjects[j].next_subjects++;
            }
        }
        //���û��next��ָ������¼�
        for (int i = 0; i < size; i++) {
            if (subjects[i].next_subjects == 0) {
                subjects[size].last_subjects++;
                subjects[size].last.push_back(i);
                subjects[i].next_subjects++;
                subjects[i].next.push_back(size);
            }
        }
        size++;
    }

    // ����ؼ�·��
    bool calculateKeyWay() {
        queue<int> que;
        stack<int> sta;
        int count = 0;
        // ����ǰ����Ŀ�Ľڵ㿪ʼ�������򲢼���min_start_time��ve��
        for (int i = 0; i < size; i++) {
            if (subjects[i].last_subjects == 0) {
                que.push(i);
            }
        }
        while (count < size && !que.empty()) {
            int j = que.front();
            que.pop();
            sta.push(j);
            count++;
            for (auto next : subjects[j].next) {
                if (--subjects[next].last_subjects == 0)
                    que.push(next);
                subjects[next].min_start_time = max(subjects[next].min_start_time, subjects[j].min_start_time + subjects[j].time_consuming);
            }
        }
        if (count != size || !que.empty()) {
            return false;
        }
        // ����max_start_time(vl)
        for (int i = 0; i < size; i++) {
            subjects[i].max_start_time = subjects[size - 1].min_start_time;
        }
        while (!sta.empty()) {
            int j = sta.top();
            sta.pop();
            for (int i : subjects[j].next) {
                subjects[j].max_start_time = min(subjects[i].max_start_time - subjects[j].time_consuming, subjects[j].max_start_time);
            }
        }
        // e l�ؼ�·��
        for (int i = 0; i < size - 1; i++) {
            for (int j : subjects[i].next) {
                int e = subjects[i].min_start_time;
                int l = subjects[j].max_start_time - subjects[i].time_consuming;
                if (e == l) {
                    subjects[i].important = 1;
                    break;
                }
            }
        }
        return true;
    }
    
    // ��ӡ��
    void printAns() 
    {
        if (!calculateKeyWay()) {
            cout << "error!�޷���������" << endl;
            return;
        }
        subjects.pop_back();
        for (Subject i : subjects) {
            cout << i.min_start_time + i.time_consuming << ' ' << i.important << endl;
        }
    }
};

int main()
{
    Graph G;
    G.f_in();
    G.printAns();
    return 0;
}
