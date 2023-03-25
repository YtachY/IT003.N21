#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 1e9;

void readInput(int &a, int &b, vector <vector <int>> &v) {
  ios::sync_with_stdio(0);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  cin >> a >> b;
  for (int i = 0; i < a; ++i) {
    vector <int> temp;
    for (int j = 0; j < b; ++j) {
      int t = 0;
      cin >> t;
      temp.push_back(t);
    }
    v.push_back(temp);
  }
}

int main() {
  vector <vector <int>> a;
  int m, n;
  int result = MAX;
  readInput(n, m, a);
  for (int i = 1; i < n - 1; ++i) {
    for (int j = 1; j < m - 1; ++j) {
      int sum = a[i - 1][j - 1]   + a[i - 1][j]   + a[i - 1][j + 1]
                + a[i][j - 1]     + a[i][j]       + a[i][j + 1]
                + a[i + 1][j - 1] + a[i + 1][j]   + a[i + 1][j + 1];
      if (sum < result) {
        result = sum;
      }
      // cout << "a(" << i << ", " << j << ") = " << a[i][j] << "\t";
      // cout << "SUM: " << sum << endl;
    }
  }
  cout << result;
  // for (int i = 0; i < n; ++i) {
  //   for (int j = 0; j < m; ++j) {
  //     cout << a[i][j] << ' ';
  //   }
  //   cout << endl;
  // }

  return 0;
}