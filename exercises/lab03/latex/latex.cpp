#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool checkValid(const std::string& str) {
  std::stack<char> s;
  for (char c : str) {
    if (c == '(' || c == '[' || c == '{') {
      s.push(c);
    } else if (c == ')' || c == ']' || c == '}') {
      if (s.empty()) {
        return false;  // no matching opening bracket
      }
      char top = s.top();
      s.pop();
      if ((c == ')' && top != '(') ||
          (c == ']' && top != '[') ||
          (c == '}' && top != '{')) {
        return false;  // mismatched brackets
      }
    }
  }
  return s.empty();  // all opening brackets have been matched
}

int main() {
  ios::sync_with_stdio(0);
  freopen("input.txt", "r", stdin);
  string s;
  cin >> s;

  bool result = checkValid(s);
  cout << (int)result;
  return 0;
}