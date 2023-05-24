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
  SinglyLinkedListNode* next;

  SinglyLinkedListNode(int node_data) {
    this->data = node_data;
    this->next = nullptr;
  }
};

class SinglyLinkedList {
 public:
  SinglyLinkedListNode* head;
  SinglyLinkedListNode* tail;

  SinglyLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
  }

  void insert_node(int node_data) {
    SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

    if (!this->head) {
      this->head = node;
    } else {
      this->tail->next = node;
    }

    this->tail = node;
  }
};

void free_singly_linked_list(SinglyLinkedListNode* node) {
  while (node) {
    SinglyLinkedListNode* temp = node;
    node = node->next;

    free(temp);
  }
}

void printLinkedList(SinglyLinkedListNode* head) {
  while (head != NULL) {
    cout << head->data << ' ';
    head = head->next;
  }
}

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
SinglyLinkedListNode* insertSortedLinkedList(SinglyLinkedListNode* head, int x) {
  // ###INSERT CODE HERE -
  SinglyLinkedListNode* newNode = new SinglyLinkedListNode(x);
  // cout << "HEAD: " << head << endl;
  if (!head || x < head->data) {
    newNode->next = head;
    head = newNode;
    // cout << "newNode: " << newNode << endl;
    // result = head;
  } else {
    SinglyLinkedListNode* currentNode = head;
    while (currentNode->next && x > currentNode->next->data) {
      // cout << "currentNode->data: " << currentNode->data << "\t"
      //      << "data: " << x << "\t"
      //      << "currentNode->next->data: " << currentNode->next->data << endl;
      currentNode = currentNode->next;
    }
    newNode->next = currentNode->next;
    currentNode->next = newNode;
  }
  return head;
}

int main() {
  ios::sync_with_stdio(0);
  freopen("input.txt", "r", stdin);
  SinglyLinkedList* llist = new SinglyLinkedList();
  int llist_count;
  int x;

  cin >> llist_count;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int i = 0; i < llist_count; i++) {
    int llist_item;
    cin >> llist_item;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    llist->insert_node(llist_item);
  }
  cin >> x;
  llist->head = insertSortedLinkedList(llist->head, x);
  printLinkedList(llist->head);

  return 0;
}
