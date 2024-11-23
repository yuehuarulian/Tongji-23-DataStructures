#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int T, m, n;
vector<int>a;
vector<int>b;
vector<int>c;
void Merge()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    for (int i = 1; i <= n; i++)
    {
        heap.push({ a[1] + b[i], 1 });
    }
    for (int i = 1; i <= n; i++)
    {
        pair<int, int> temp = heap.top();
        heap.pop();
        c[i] = temp.first;
        heap.push({ temp.first - a[temp.second] + a[temp.second + 1], temp.second + 1 });//把所有a和b[x]加一遍
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] = c[i];
    }
}
//void Merge(vector<int>& p1, const vector<int>& p2)
//{
//    priority_queue<int, vector<int>, greater<int>> pq;
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++) {
//            int t = p1[i] + p2[j];
//            //if (t >= pq)
//            //    continue;
//            pq.push(p1[i] + p2[j]);
//        }
//    }
//    for (int i = 1; i <= n; i++)
//    {
//        p1[i] = pq.top();
//        pq.pop();
//    }
//}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> m >> n;
        a.resize(n + 1);//n
        b.resize(n + 1);
        c.resize(n + 1);
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
		for (int i = 2; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> b[j];
            }
            Merge();
		}
        for (int i = 1; i <= n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }


    return 0;
}