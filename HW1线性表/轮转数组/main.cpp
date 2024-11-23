#include <iostream>
using namespace std;
#define ll long long
typedef struct {
	ll* elem;
	ll length;
	ll listsize;
}Sqlist;
//��ʼ��
bool Initial_Sqlist(Sqlist &L,int n)
{
	L.elem = (ll*)malloc(n * sizeof(ll));
	if (!L.elem)
		return false;
	L.length = 0;
	L.listsize = n;
	return true;
}
//���
void Out_Sqlist(Sqlist& L)
{
	for (ll i = 0; i < L.length; i++)
		cout << L.elem[i] << ' ';
}
int main()
{
	int n, k;
	cin >> n >> k;
	k = k % n;//�״���ȡ��
	Sqlist sum;
	if (!Initial_Sqlist(sum, n))
		return 0;
	for (ll i = 0; i < n; i++)
		cin >> *(sum.elem + i);//sum.elem[i]
	sum.length += n;
	Sqlist sum2;
	if (!Initial_Sqlist(sum2, n))
		return 0;
	//��ת����
	for (ll i = 0; i < n; i++)
		sum2.elem[i] = sum.elem[(i + n - k) % n];
	sum2.length += n;
	Out_Sqlist(sum2);

	return 0;
}