#include <iostream>
using namespace std;

// Cấu trúc của một node
struct NODE {
  int info;
  NODE *next;
};
// Cấu trúc của một DSLK
struct Stack {
  NODE *head;
  NODE *tail;
};

int isEmpty(Stack &s) {
  if (s.head == NULL)  // Stack rong

    return 1;

  return 0;
}
void Push(Stack &s, NODE *p) {  // AddHead
  if (s.head == NULL) {
    s.head = p;
    s.tail = p;
  } else {
    p->next = s.head;
    s.head = p;
  }
}
bool Pop(Stack &s, int &x) {
  NODE *p;
  if (isEmpty(s) != 1) {
    if (s.head != NULL) {
      p = s.head;
      x = p->info;
      s.head = s.head->next;
      if (s.head == NULL)
        s.tail = NULL;
      return 1;
    }
  }
  return 0;
}
// ###INSERT CODE HERE -
void CreateEmptyList(Stack &mList) {
  mList.head = NULL;
  mList.tail = NULL;
}
NODE *createNode(int value) {
  NODE *p = new NODE;
  if (p == NULL) {
    exit(1);
  }
  p->info = value;
  p->next = NULL;
  return p;
}

void AddTail(Stack &mList, NODE *p) {
  if (mList.head == NULL) {
    mList.head = p;
    mList.tail = mList.head;
  } else {
    mList.tail->next = p;
    mList.tail = p;
  }
}

void AddHead(Stack &mList, NODE *p) {
  if (mList.tail == NULL) {
    mList.tail = p;
    mList.head = mList.tail;
  } else {
    p->next = mList.head;
    mList.head = p;
  }
}
void CreateList(Stack &mList) {
  int x;

  while (1) {
    // cout << "Nhap gia tri node tiep theo: ";
    cin >> x;
    if (x == -1) {
      break;
    }
    NODE *p = createNode(x);
    AddHead(mList, p);
  }
}
void Print(Stack L) {
  for (NODE *i = L.head; i != NULL; i = i->next) {
    cout << i->info << " ";
  }
}

int main() {
  ios::sync_with_stdio(0);
  freopen("input.txt", "r", stdin);

  Stack myStack;
  CreateEmptyList(myStack);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int temp;
    cin >> temp;
    Push(myStack, createNode(temp));
  }
  for (int i = 0; i < n; ++i) {
    int temp;
    if (Pop(myStack, temp)) {
      cout << temp << " ";
    }
  }
  return 0;
}