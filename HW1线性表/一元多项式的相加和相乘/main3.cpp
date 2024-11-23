#include <iostream>
#include <cstdlib>
using namespace std;
#define   OK                    1
#define   ERROR                 0
#define   OVERFLOW             -2
#define   TRUE                  1
#define   FALSE                 0
typedef   int   Status;
typedef struct {
    int coef;
    int expn;
}term, ElemType;//两个类型：term用于本ADT，ElemType为LinkList的数据对象名

typedef struct LNode{//节点类型
    ElemType  data;
    struct LNode* next;
}LNode, * LinkList;

typedef LinkList polynomial;

void CreatPolyn(polynomial& L, int n)//输入n项的系数和指数，建立表示一元多项式的有序链表P
{
    LinkList p, q;
    //
    L = (LinkList)malloc(sizeof(LNode));///头
    q = L;//记录
    L->next = NULL;
    //
    if (n == 0)
        return;
    for (int i = 0; i < n; i++) {
        p = (LinkList)malloc(sizeof(LNode));//新
        cin >> p->data.coef >> p->data.expn;
        p->next = NULL;
        q->next = p;
        q = q->next;
    }
}
void ClearList(LinkList L)
{
    LinkList p = L->next;
    while (L) {
        free(L);
        L = p;
        if (p)
            p = p->next;
    }
}
polynomial AddPolyn(polynomial& Pa, polynomial& Pb)
{
    LinkList qa = Pa->next;
    LinkList qb = Pb->next;
    LinkList Pc, qc;
    //
    Pc = (LinkList)malloc(sizeof(LNode));
    Pc->next = NULL;
    qc = Pc;
    //
    while (qa && qb) {
        LinkList e = (LinkList)malloc(sizeof(LNode));
        if (qa->data.expn == qb->data.expn) {
            e->data.coef = qa->data.coef + qb->data.coef;
            e->data.expn = qa->data.expn;
            qa = qa->next;
            qb = qb->next;
        }
        else {
            e->data = (qa->data.expn < qb->data.expn) ? qa->data : qb->data;
            (qa->data.expn < qb->data.expn) ? qa = qa->next : qb = qb->next;
        }
        if (e->data.coef != 0) {
            qc->next = e;
            e->next = NULL;
            qc = qc->next;
        }
    }
    while (qa) {
        LinkList e = (LinkList)malloc(sizeof(LNode));
        e->data = qa->data;
        qa = qa->next;
        qc->next = e;
        e->next = NULL;
        qc = qc->next;
    }
    while (qb) {
        LinkList e = (LinkList)malloc(sizeof(LNode));
        e->data = qb->data;
        qb = qb->next;
        qc->next = e;
        e->next = NULL;
        qc = qc->next;
    }
    return Pc;
}
polynomial MulPolyn(polynomial& Pa, polynomial& Pb)
{
    LinkList qa = Pa->next, qb = Pb->next;
    LinkList Pd, qd;
    //
    Pd = (LinkList)malloc(sizeof(LNode));
    Pd->next = NULL;
    qd = Pd;
    //
    if (qa && qb)
    {
        while (qa)
        {
            LinkList Pc, qc;
            //
            Pc = (LinkList)malloc(sizeof(LNode));
            Pc->next = NULL;
            qc = Pc;
            //
            qb = Pb->next;
            while (qb)
            {
                LinkList e = (LinkList)malloc(sizeof(LNode));
                e->data.coef = qb->data.coef * qa->data.coef;
                e->data.expn = qb->data.expn + qa->data.expn;
                qc->next = e;
                qc = qc->next;
                qc->next = NULL;
                qb = qb->next;
            }
            qa = qa->next;
            LinkList Pe = Pd;
            Pd = AddPolyn(Pc, Pd);
            ClearList(Pe);//释放
            ClearList(Pc);
        }
    }
    return Pd;
}
void f_out(LinkList L)
{
    LinkList p = L->next;
    while (p) {
        cout << p->data.coef << ' ' << p->data.expn << ' ';
        p = p->next;
    }
    cout << endl;
}
int main()
{
    polynomial A, B;
    int length;
    cin >> length;
    CreatPolyn(A, length);
    //输入B
    cin >> length;
    CreatPolyn(B, length);
    //进行相加
    int option;
    cin >> option;
    if (option == 0) {
        polynomial C = AddPolyn(A, B);
        f_out(C);
    }
    else if (option == 1) {
        polynomial C = MulPolyn(A, B);
        f_out(C);
    }
    else {
        polynomial C = AddPolyn(A, B);
        f_out(C);
        ClearList(C);
        polynomial D = MulPolyn(A, B);
        f_out(D);
    }
    //这时候A是合并后的结果
   // ListTraverse(A, visit);
    return 0;
}