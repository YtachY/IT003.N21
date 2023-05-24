/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
###End banned keyword*/

#include <iostream>
#include <limits>
using namespace std;

class SinglyLinkedListNode {
 public:
  int data;
  SinglyLinkedListNode *next;

  SinglyLinkedListNode(int node_data) {
    this->data = node_data;
    this->next = nullptr;
  }
};

class SinglyLinkedList {
 public:
  SinglyLinkedListNode *head;
  SinglyLinkedListNode *tail;

  SinglyLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
  }
};

// Complete the insertSortedLinkedList function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

// ###INSERT CODE HERE -
void insert_node(SinglyLinkedList *list, int item) {
  SinglyLinkedListNode *node = new SinglyLinkedListNode(item);

  if (!list->head) {
    list->head = node;
  } else {
    node->next = list->head;
    list->head = node;
  }
}

void printLinkedList(SinglyLinkedList *list) {
  SinglyLinkedListNode *head = list->head;
  while (head != NULL) {
    cout << head->data << ' ';
    head = head->next;
  }
}
void reverseLinkedList(SinglyLinkedList *list) {
}
int main() {
  ios::sync_with_stdio(0);
  freopen("input.txt", "r", stdin);
  SinglyLinkedList *llist = new SinglyLinkedList();
  int llist_count;

  cin >> llist_count;

  for (int i = 0; i < llist_count; i++) {
    int llist_item;
    cin >> llist_item;

    insert_node(llist, llist_item);
  }

  reverseLinkedList(llist);
  printLinkedList(llist);

  return 0;
}
