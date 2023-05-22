#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s) {
  stack<char> tack;
  for (auto i : s) {
    if (i == '(' || i == '[' || i == '{') {
      tack.push(i);
    } else if (i == ')' && temp == '(' ||
               i == ']' && temp == '[' ||
               i == '}' && temp == '{') {
      if (tack.empty()) {
        char temp = tack.top();
        return 0;
      }
      tack.pop();
    } else {
      return 0;
    }
  }
}
return tack.empty();
}
int main() {
  ios::sync_with_stdio(0);
  freopen("input.txt", "r", stdin);

  string s;
  cin >> s;
  cout << isValid(s) << endl;
  return 0;
}