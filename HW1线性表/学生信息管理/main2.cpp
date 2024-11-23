#include <iostream>
#include <string>
#include <string.h>
using namespace std;
#define ll long long
#define LISTINCREMENT 10
typedef struct {
	char no[20];
	//string no;
	char name[20];
	//string name;
}people;
typedef struct {
	people* elem;
	int length;
	int listsize;
}Sqlist;
bool Initial_Sqlist(Sqlist& L, int n)
{
	L.elem = (people*)malloc(n * sizeof(people));
	if (!L.elem)
		return false;
	L.length = 0;
	L.listsize = n;
	return true;
}
int Insert_Sqlist(Sqlist& L, int num, people e) 
{
	if (num<1 || num>L.length + 1)
		return -1;
	if (L.length >= L.listsize) {
		people* newbase = (people*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(people));
		if (!newbase)
			return -2;//overflow
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	people* q = &(L.elem[num - 1]);
	if(L.length){
		for (people* p = &(L.elem[L.length - 1]); p >= q; --p)//L.length==0的时候不能
			*(p + 1) = *p;
	}
	*q = e;
	++L.length;
	return 0;
}
int ListDelete_sq(Sqlist& L, int i) {
	if (i<1 || i>L.length)
		return -1;
	people* p = &(L.elem[i - 1]);
	people* q = L.elem + L.length - 1;
	for (p++; p <= q; ++p)
		*(p - 1) = *p;
	--L.length;
	return 0;
}
int LocateElem_Sq(Sqlist& L, string a, char b[])
{
	int i = 1;
	if (a == "name") {
		while (i <= L.length && strcmp(b, L.elem[i - 1].name))
			++i;
	}
	else {
		while (i <= L.length && strcmp(b, L.elem[i - 1].no))
			++i;
	}
	if (i <= L.length)
		return i;
	return -1;
}
int main()
{
	int n;
	cin >> n;
	Sqlist L;
	
	if (!Initial_Sqlist(L, n + 10))
		return 0;
	for (int i = 0; i < n; i++) {
		cin >> L.elem[i].no >> L.elem[i].name;
	}
	L.length += n;

	while (1) {
		string ch;
		cin >> ch;
		if (ch == "end")
			break;
		if (ch == "insert") {
			int num;
			people* e = (people*)malloc(sizeof(people));
			cin >> num >> e->no >> e->name;
			cout << Insert_Sqlist(L, num, *e) << endl;
		}
		else if (ch == "remove") {
			int num;
			cin >> num;
			cout << ListDelete_sq(L, num) << endl;
		}
		else if (ch == "check") {
			string a;
			char b[20];
			cin >> a >> b;
			int num = LocateElem_Sq(L, a, b);
			if (num == -1)
				cout << num << endl;
			else
				cout << num << ' ' << L.elem[num - 1].no << ' ' << L.elem[num - 1].name << endl;
		}

	}
	cout << L.length << endl;

	return 0;
}

