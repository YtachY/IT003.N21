#include <iostream>
#include <vector>

using namespace std;

void readInput(string &a, string &b) {
  ios::sync_with_stdio(0);
  // freopen("input.txt", "r", stdin);
  cin >> a >> b;
}
int main() {
  string a, b;
  vector<int> result;
  readInput(a, b);

  // cout << a << b;
  if (a.size() >= b.size()) {
    /* code */
    for (int i = 0; i < a.size(); ++i) {
      // int temp = 0;
      for (int j = 0; j < b.size(); ++j) {
        int temp = i + j;
        if (a[temp] != b[j]) {
          break;
        }
        if (j == b.size() - 1) {
          result.push_back(i + 1);
        }
      }
    }
  } else {
  }
  if (result.empty()) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    for (auto i : result) {
      cout << i << ' ';
    }
  }

  return 0;
}