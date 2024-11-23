#include <iostream>
using namespace std;
#define ll long long
#define LIST_INIT_SIZE 3000
#define LISTINCREMENT 1000
#define overflow -2
typedef struct {
	int* elem;
	int length;
	int listsize;
}Sqlist;

bool Initial_Sqlist(Sqlist& L, int n)
{
	L.elem = (int*)malloc(n * sizeof(int));
	if (!L.elem)
		return false;
	L.length = 0;
	L.listsize = n;
	for (int i = 1; i <= n; i++)
		L.elem[i - 1] = 0;
	return true;
}
int Increase_Judge_Sqlist(Sqlist& L)
{
	if (L.length >= L.listsize) {
		int* newbase = (int*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(int));
		if (!newbase)
			return overflow;
		L.elem = newbase;
		for (int i = L.listsize + 1; i <= (L.listsize + LISTINCREMENT); i++)
			L.elem[i - 1] = 0;
		L.listsize += LISTINCREMENT;
	}
}
void Mul_List(Sqlist& L, int A)
{
	for (int i = L.length; i >= 1; i--) {
		L.elem[i - 1] *= A;
		for (int j = i; L.elem[j - 1] / 10; j++) {
			if (j == L.length) {
				Increase_Judge_Sqlist(L);
				L.length++;
			}
			L.elem[j] += L.elem[j - 1] / 10;
			L.elem[j - 1] %= 10;
		}
	}
}
void Add_List(Sqlist& L1, const Sqlist L2)
{
	int* q1 = L1.elem;
	int* q2 = L2.elem;
	int* p2 = L2.elem + L2.length - 1;
	for (; q2 <= p2; q2++, q1++) {
		if ((q1 - L1.elem + 1) > L1.length) {
			Increase_Judge_Sqlist(L1);
			L1.length++;
		}
		*q1 += *q2;
		for (int* q = q1; *q / 10; q++) {
			if (q - L1.elem + 1 == L1.length) {
				Increase_Judge_Sqlist(L1);
				L1.length++;
			}
			*(q + 1) += *q / 10;
			*q %= 10;
		}
	}
}
int main()//iA^i
{
	int N, A;
	cin >> N >> A;
	if (A == 0)
		cout << '0' << endl;
	Sqlist Sum;
	Initial_Sqlist(Sum, LIST_INIT_SIZE);
	for (int i = 1; i <= N; i++) {//Éú³Éi*A^i
		Sqlist ni;
		Initial_Sqlist(ni, LIST_INIT_SIZE);
		int B = A * i;
		for (int j = 0; B; j++) {
			Increase_Judge_Sqlist(ni);
			ni.elem[j] = B % 10;
			B /= 10;
			ni.length++;
		}
		for (int j = 1; j <= (i - 1); j++) {
			Mul_List(ni, A);
		}
		Add_List(Sum, ni);
		free(ni.elem);
	}
	int* p = Sum.elem + Sum.length - 1;
	int* q = Sum.elem;
	for (; p >= q; p--) {
		cout << *p;
	}
	cout << endl;
}