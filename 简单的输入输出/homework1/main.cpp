#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double a[12] = { 0 };
	double sum = 0;
	for (int i = 0; i < 12; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sum /= 12;
	cout << "¥" << setiosflags(ios::fixed) << setprecision(2) << sum << '\n';
	return 0;
}