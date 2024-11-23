#include <iostream>
#include <iomanip>
#include <stdio.h>
#define ll long long
using namespace std;
/*每年，这种蜜蜂中的一只雌性蜜蜂会生育一只雄性蜜蜂，
而一只雄性蜜蜂会生育一只雌性蜜蜂和一只雄性蜜蜂，
生育后它们就会死去。*/
ll a[100][2];//第一个放雄蜂数目，第二个放总数目，天数0—99
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
	//雄蜂=a[n-1][0],雌蜂=a[n-1][1]-a[n-1][0]
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