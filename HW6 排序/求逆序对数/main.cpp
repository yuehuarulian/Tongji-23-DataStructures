#include<iostream>
using namespace std;
long long int  SUM;
int N;
long long int NUM[20009];
long long int TMP[20009];
void Merge(int l,int m,int n)
{
	int i = l;
	int k = i; 
	int j = m + 1;
	for (; i <= m && j <= n; k++) {
		if (NUM[i] <= NUM[j])
			TMP[k] = NUM[i++];
		else {
			SUM += m+1 - i;
			TMP[k] = NUM[j++];
		}
	}
	while (i <= m) {
		TMP[k++] = NUM[i++];
	}
	while (j <= n) {
		TMP[k++] = NUM[j++];
	}
	for (int p = l; p <= n; p++) {
		NUM[p] = TMP[p];
	}
}
void MSort(int s,int t)
{
	if (s >= t)
		return;
	else {
		int m = (s + t) >> 1;
		MSort(s, m);
		MSort(m + 1, t);
		Merge(s,m,t);
	}
}



int main()
{
	while (1) {
		cin >> N;
		if (!N)
			break;
		for (int i = 1; i <= N; i++) {
			cin >> NUM[i];
		}
		SUM = 0;
		MSort(1, N);
		cout << SUM << endl;
	}
}