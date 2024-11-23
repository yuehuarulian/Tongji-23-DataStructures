#include <iostream>
#include <iomanip>
#include <stdio.h>
#define ll long long
#define NUM_MAX 10000001
using namespace std;
int main()
{
	ll n, m;
	cin >> n >> m;
	ll a = 0;
	for (int i = 2; i <= n; i++)
		a = (a + m) % i;
	cout << a << endl;
	return 0;
}