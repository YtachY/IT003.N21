#include <iostream>
using namespace std;

// Cấu trúc của một node
struct NODE {
  int info;
  NODE *next;
};
// Cấu trúc của một DSLK
struct LIST {
  NODE *head;
  NODE *tail;
};

// ###INSERT CODE HERE -
void CreateEmptyList(LIST &mList) {
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

void AddTail(LIST &mList, NODE *p) {
  if (mList.head == NULL) {
    mList.head = p;
    mList.tail = mList.head;
  } else {
    mList.tail->next = p;
    mList.tail = p;
  }
}
void CreateList(LIST &mList) {
  int x;

  while (1) {
    // cout << "Nhap gia tri node tiep theo: ";
    cin >> x;
    if (x == -1) {
      break;
    }
    NODE *p = createNode(x);
    AddTail(mList, p);
  }
}
// void selectionSort(LIST &L) {
//   NODE *min;
//   for (NODE *i = L.head; i != L.tail; i = i->next) {
//     min = i;
//     for (NODE *j = i->next; j != NULL; j = j->next)
//       if (j->info < min->info) min = j;
//     swap(i->info, min->info);
//   }
// }
// void Print(LIST mList) {
//   selectionSort(mList);
//   for (NODE *i = mList.head; i != NULL; i = i->next) {
//     if (i->info != mList.head->info) {
//       cout << "Second min: ";
//       cout << i->info;
//       break;
//     }
//   }
// }
void Print(LIST L) {
  NODE *min1 = L.head;
  NODE *min2 = L.head->next;
  for (NODE *i = L.head; i != NULL; i = i->next) {
    if (i->info < min1->info) {
      min2 = min1;
      min1 = i;
    } else if (i->info > min1->info && i->info < min2->info) {
      min2 = i;
    }
  }
  cout << min2->info;
}

int main() {
  LIST L;
  CreateEmptyList(L);
  CreateList(L);
  Print(L);
  return 0;
}