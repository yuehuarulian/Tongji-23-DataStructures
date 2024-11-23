#include <iostream>
#include <stdio.h>
#define num_max 300
#define ll long long
using namespace std;
int main()
{
	while (1) {
		ll sum = 0;
		char ch[num_max] = { 0 };
		fgets(&ch[1], num_max, stdin);
		if (ch[1] == '#')
			break;
		for (unsigned int i = 1; ch[i]; i++) {
			if (ch[i] == ' ')
				;
			else if (ch[i] >= 'A' && ch[i] <= 'Z')
				sum += i * (ch[i] - 'A' + 1);
		}
		cout << sum << endl;
	}
	/*while (1) {
		ll sum = 0;
		bool end = 0;
		for (int i = 1; i <= num_max; i++) {
			const int ch = getchar();
			if (ch == '#') {
				end = 1;
				break;
			}
			else if (ch == '\n'||ch=='\r') {
				cout << sum << '\n';
				break;
			}
			else if (ch == ' ')
				;
			else if (ch >= 'A' && ch <= 'Z')
				sum += i * (ch - 'A' + 1);
			else
				i--;
		}
		if (end)
			break;
	}*/
	return 0;
}