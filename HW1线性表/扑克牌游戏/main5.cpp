#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;
const string color_all[4] = { "Spade","Heart","Club","Diamond" };
//���ң�Spade�������ģ�Heart����÷����Club�������飨Diamond��
const string num_all[14] = { "","A","2","3","4","5","6","7","8","9","10","J","Q","K" };
//                1 2 3 4 5 6 7 8 9 10 11 12 13
//��Ŵ�С����Ϊ��A,2,3,4,5,6,7,8,9,10, J, Q, K
const string command_all[4] = { "Append","Extract","Revert","Pop" };
/*
1) ��ӣ�Append�������һ���˿��Ƶ��ƶѵĵײ�����Append Club Q��
2) ��ȡ��Extract�������ƶ��г�ȡĳ�ֻ�ɫ�������ƣ���С����������򣬷ŵ���������Extract Heart��
3)��ת��Revert����ʹ�����ƶ�����
4)������Pop����
*/
string command_each;
int n;
map<int, int> mp;

struct pocker {
	int color;
	int num;
public:
	pocker(int col, int n) {
		color = col;
		num = n;
	}
};
deque<pocker>po;
pocker found_pocker(string color, string num)//���ر�color��num��ʼ�����pocker
{
	int col, n;
	for (col=0; color != color_all[col]; col++)
		;
	for (n = 1; num != num_all[n]; n++)
		;
	pocker elem(col, n);
	return elem;
}
string find_color(pocker elem)
{
	return color_all[elem.color];
}
string find_num(pocker elem)
{
	return num_all[elem.num];
}
void pocker_Append(pocker elem)
{
	po.push_back(elem);
}
bool cmp(pocker v1, pocker v2)//��С��������
{
	return v1.num <= v2.num;
}
void pocker_Extract(int color)
{
	deque<pocker>same_color_po;
	for (deque<pocker>::const_iterator i = po.begin(); i != po.end(); i++) {
		if ((*i).color == color){
			same_color_po.push_back(*i);
			//po.erase(i);
		}
	}
	sort(same_color_po.begin(), same_color_po.end(), cmp);
	while (!po.empty()) {
		pocker elem = po.front();
		po.pop_front();
		if (elem.color != color) {
			same_color_po.push_back(elem);
		}
	}
	po = same_color_po;
	//for (deque<pocker>::const_iterator i = same_color_po.begin(); i != po.end(); i++) {
	//	pocker elem = same_color_po.front();
	//	po.push_back(elem);
	//	same_color_po.pop_front();
	//}
}
void pocker_Revert()
{
	deque<pocker>po_reverse;
	while(!po.empty()){
		pocker elem = po.front();
		po_reverse.push_front(elem);
		po.pop_front();
	}
	po = po_reverse;
}
void pocker_Pop()
{
	if (po.empty())
		cout << "NULL" << endl;
	else {
		pocker elem = po.front();
		cout << find_color(elem) << ' ' << find_num(elem) << endl;
		po.pop_front();
	}
}

int main()
{
	cin >> n;
	while (n--) {
		cin >> command_each;
		int i;
		for (i = 0; command_each != command_all[i]; i++)
			continue;
		switch (i) {
			case 0: {
				string num, color;
				cin >> color >> num;
				pocker elem = found_pocker(color, num);
				pocker_Append(elem);
				break;
			}
			case 1:{
				string color;
				cin >> color;
				int col;
				for (col = 0; color_all[col] != color; col++)
					;
				pocker_Extract(col);///
				break;
			}
			case 2:
				pocker_Revert();
				break;
			case 3:
				pocker_Pop();
				break;
		}
	}
	for (deque<pocker>::const_iterator i = po.begin(); i != po.end(); i++) {
		cout << find_color(*i) << ' ' << find_num(*i) << endl;
	}

}
