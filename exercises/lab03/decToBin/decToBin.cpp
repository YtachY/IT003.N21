#include <iostream>
#include <stack>

using namespace std;

string convertDecToBin(int x) {
  stack<bool> tack;
  string result = "";
  while (x > 0) {
    if (x % 2 == 1) {
      tack.push(1);
    } else {
      tack.push(0);
    }
    x /= 2;
  }
  while (!tack.empty()) {
    if (tack.top()) {
      result += "1";
    } else {
      result += "0";
    }
    tack.pop();
  }
  return result;
}

int main() {
  ios::sync_with_stdio(0);
  freopen("input.txt", "r", stdin);
  int n;
  cin >> n;
  cout << convertDecToBin(n) << endl;
  return 0;
}