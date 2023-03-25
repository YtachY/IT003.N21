#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


void readInput(string &a, string &b) {
  ios::sync_with_stdio(0);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  cin >> a >> b;
}

int main() {
  string a, b;
  int result = 0;
  readInput(a, b);
  
  if (a.size() < b.size()) {
    result = b.size();
  }
  else {
    for (int i = 0; i < b.size(); ++i) {
      if (a[i] != b[i]) {
        result = b.size() - i;
        break;
      }
    }
  }
  cout << result;
  return 0;
}