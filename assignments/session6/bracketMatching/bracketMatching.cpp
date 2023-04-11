#include <iostream>
#include <string>
using namespace std;
struct NODE {
  char info;
  NODE* next;
};
struct Stack {
  NODE* head;
  NODE* tail;
};

NODE* CreateNode(char x) {
  NODE* p = new NODE;
  if (p == NULL)
    exit(1);
  p->info = x;
  p->next = NULL;
  return p;
}

// Stack
void CreateEmptyStack(Stack& l) {
  l.head = NULL;
  l.tail = NULL;
}
bool isEmpty(Stack l) {
  if (l.head == NULL)
    return 1;
  return 0;
}
void Push(Stack& l, NODE* p) {
  if (l.head == NULL) {
    l.head = p;
    l.tail = p;
  } else {
    p->next = l.head;
    l.head = p;
  }
}
void Pop(Stack& l) {
  if (isEmpty(l) == 0)
    if (l.head != NULL) {
      l.head = l.head->next;
      if (l.head == NULL)
        l.tail = NULL;
    }
}

NODE* Top(Stack l) {
  return l.head;
}
int main() {
  ios::sync_with_stdio(0);
  freopen("input.txt", "r", stdin);
  string chuoi;
  getline(cin, chuoi);
  cout << chuoi << endl;
  Stack s;
  CreateEmptyStack(s);
  for (int i = 0; i < chuoi.length(); i++) {
    if (chuoi[i] == '(') {
      char x = chuoi[i];
      Push(s, CreateNode(x));
    } else if (chuoi[i] == ')') {
      if (isEmpty(s)) {
        cout << "False";
        return 1;
      } else {
        Pop(s);
      }
    }
  }

  if (isEmpty(s) == 1)
    cout << "True";
  else
    cout << "False";
  return 1;
}