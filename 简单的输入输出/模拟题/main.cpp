#include <iostream>
#include <iomanip>
#include <stdio.h>
#define ll long long
using namespace std;
/*ÿ�꣬�����۷��е�һֻ�����۷������һֻ�����۷䣬
��һֻ�����۷������һֻ�����۷��һֻ�����۷䣬
���������Ǿͻ���ȥ��*/
ll a[100][2];//��һ�����۷���Ŀ���ڶ���������Ŀ������0��99
void dfs(int n)
{
	if (a[n][1])
		return;

	if (n == 0) {
		a[n][0] = 0;
		a[n][1] = 1;
		return;
	}
	if (!a[n - 1][1])
		dfs(n - 1);
	//�۷�=a[n-1][0],�Ʒ�=a[n-1][1]-a[n-1][0]
	a[n][0] = (a[n - 1][1] - a[n - 1][0]) + (a[n - 1][0]);
	a[n][1] = a[n - 1][0] + 1 + a[n][0];
	return;
}
int main()
{
	while (1) {
		int n;
		cin >> n;
		if (n == -1)
			break;
		else
			dfs(n);

		cout << a[n][0] << ' ' << a[n][1] << '\n' << endl;
	}
	return 0;
}