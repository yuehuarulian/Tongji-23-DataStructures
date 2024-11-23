#include <iostream>
#include <map>
#include <string>
#include <stack>
using namespace std;
/*
X is a child of Y.
X is the parent of Y.
X is a sibling of Y.
X is a descendant of Y.
X is an ancestor of Y.

6 5
John
 Robert
  Frank
  Andrew
 Nancy
  David
Robert is a child of John.
Robert is an ancestor of Andrew.
Robert is a sibling of Nancy.
Nancy is the parent of Frank.
John is a descendant of Andrew.
2 1
abc
 xyz
xyz is a child of abc.
0 0
*/
int n, m;
map<string, pair<int, string>>MAP;//名字 层数 父母
bool judgechild(string name1, string name2)
{
	return (MAP[name1].second == name2);
}
bool judgeparent(string name1, string name2)
{
	return (MAP[name2].second == name1);
}
bool judgesibling(string name1, string name2)
{
	return (MAP[name1].second == MAP[name2].second);
}
bool judgedescendant(string name1, string name2)
{
	string descent = name1;
	while (!descent.empty()) {
		if (descent == name2)
			return true;
		descent = MAP[descent].second;
	}
	return false;
}
bool judgeancestor(string name1, string name2)
{
	string descent = name2;
	while (!descent.empty()) {
		if (descent == name1)
			return true;
		descent = MAP[descent].second;
	}
	return false;
}
int main()
{
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		stack<pair<string, int>>Stack;//名字 层数
		for (int i = 0; i < n; i++) {
			char ch;
			int emp_num = 0;
			string now, parent;
			cin.get();
			while ((ch = cin.get()) == ' ') {
				emp_num++;
			}
			cin >> now;
			now = ch + now;//他的名字
			while (!Stack.empty() && Stack.top().second >= emp_num)
				Stack.pop();
			if (!Stack.empty())
				parent = Stack.top().first;
			Stack.push(make_pair(now, emp_num));
			MAP[now] = make_pair(emp_num, parent);
		}
		for (int i = 0; i < m; i++) {
			string name1, relation, name2, a;//Robert is a child of John.
			cin >> name1;
			cin >> a;
			cin >> a;
			cin >> relation;
			cin >> a;
			cin >> name2;
			name2 = name2.substr(0, name2.length() - 1);
			if (relation == "child")
				cout << (judgechild(name1, name2) ? "True" : "False") << endl;
			else if (relation == "parent")
				cout << (judgeparent(name1, name2) ? "True" : "False") << endl;
			else if (relation == "sibling")
				cout << (judgesibling(name1, name2) ? "True" : "False") << endl;
			else if (relation == "descendant")
				cout << (judgedescendant(name1, name2) ? "True" : "False") << endl;
			else if (relation == "ancestor")
				cout << (judgeancestor(name1, name2) ? "True" : "False") << endl;
		}
		cout << endl;
		MAP.clear();
	}
}