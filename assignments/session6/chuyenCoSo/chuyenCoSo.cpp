#include <iostream>
#include <string>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

struct Stack {
  Node* top;
  Stack() {
    this->top = NULL;
  }
  void push(int data) {
    Node* node = new Node(data);
    node->next = top;
    top = node;
  }
  int pop() {
    if (top == NULL) {
      return -1;
    }
    Node* temp = top;
    top = top->next;
    int popped = temp->data;
    delete temp;
    return popped;
  }
  bool is_empty() {
    return top == NULL;
  }
};

string ChuyenCoSo(int n) {
  Stack stack;
  while (n > 0) {
    int remainder = n % 2;
    stack.push(remainder);
    n = n / 2;
  }
  string binary_str = "";
  while (!stack.is_empty()) {
    binary_str += to_string(stack.pop());
  }
  return binary_str;
}

int main() {
  int n;
  cin >> n;
  string binary_str = ChuyenCoSo(n);
  cout << binary_str << endl;
  return 0;
}
