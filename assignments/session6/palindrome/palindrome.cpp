#include <iostream>
#include <string>
using namespace std;
struct NODE {
    char info;
    NODE* pNext;
};
struct stack {
    NODE* pHead;
    NODE* pTail;
};
struct queue {
    NODE* pHead;
    NODE* pTail;
};
NODE* CreateNode(char x) {
    NODE* p = new NODE;
    if (p == NULL)
        exit(1);
    p->info = x;
    p->pNext = NULL;
    return p;
}
///stack
void CreateEmptyList(stack& L) {
    L.pHead = NULL;
    L.pTail = NULL;
}
int isEmpty(stack& s)
{
    if (s.pHead == NULL)//Stack rong return 1;
        return 0;
}
void Push(stack& s, NODE* p)
{ // AddHead
    if (s.pHead == NULL) {
        s.pHead = p; s.pTail = p;
    }
    else {
        p->pNext = s.pHead; s.pHead = p;
    }
}
bool Pop(stack& s, char& x)
{ // RemoveHead
    NODE* p;
    if (isEmpty(s) != 1) {
        if (s.pHead != NULL) {
            p = s.pHead;
            x = p->info;
            s.pHead = s.pHead->pNext;
            if (s.pHead == NULL)
                s.pTail = NULL;
            return 1;
        }
    }
    return 0;
}

///Queue
void CreateEmptyList(queue& L) {
    L.pHead = NULL;
    L.pTail = NULL;
}
int isEmpty(queue& s)
{
    if (s.pHead == NULL)//Stack rong return 1;
        return 0;
}
void EnQueue(queue& Q, NODE* p)
{// AddTail
    if (Q.pHead == NULL) {
        Q.pHead = p;
        Q.pTail = p;
    }
    else {
        Q.pTail->pNext = p;
        Q.pTail = p;
    }
}
int DeQueue(queue& Q, char& x)
{ // RemoveHead
    NODE* p;
    if (isEmpty(Q) != 1)
    {
        if (Q.pHead != NULL)
        {
            p = Q.pHead;
            x = p->info;
            Q.pHead = Q.pHead->pNext;
            if (Q.pHead == NULL)
                Q.pTail = NULL;
            return 1;
        }
    }
    return 0;
}
///------
bool cmp(char x1, char x2)
{
    if (x1 == x2)
        return 1;
    if (((x1 >= 'a' && x1 < 'z') || (x1 >= 'A' && x1 < 'Z'))
        && ((x2 >= 'a' && x2 < 'z') || (x2 >= 'A' && x2 < 'Z')))
    {
        if ((int)x1 == (int)x2 + 32 || (int)x2 == (int)x1 + 32)
            return 1;
    }
    return 0;
}
bool isPalindromes(string str)
{
    stack s;
    CreateEmptyList(s);
    queue q;
    CreateEmptyList(q);
    for (int i = 0; i < str.length() ; i++)
    {
        Push(s, CreateNode(str[i]));
        EnQueue(q, CreateNode(str[i]));
    }
    char x1, x2;
    while (Pop(s, x1) == 1 && DeQueue(q, x2) == 1)
    {
        if (!cmp(x1, x2)) {
            return 0;
        }
    }
    return 1;
}
int main()
{
    string str;
    getline(cin, str);
    if (isPalindromes(str)) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
    return 0;
}
