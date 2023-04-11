#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next;
};

struct Stack {
    Node* top;

    Stack() {
        top = NULL;
    }

    void push(string value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    string pop() {
        if (isEmpty()) {
            return "";
        }
        string result = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return result;
    }

    bool isEmpty() {
        return top == NULL;
    }
};

int main() {
    string str;
    
    getline(cin, str);
    Stack stack;
    string word = "";
    for (char c : str) {
        if (c == ' ') {
            stack.push(word);
            word = "";
        }
        else {
            word += c;
        }
    }
    stack.push(word);

    // Lấy các từ khỏi stack và in chúng ra màn hình
    while (!stack.isEmpty()) {
        cout << stack.pop() << " ";
    }
    cout << endl;

    return 0;
}
