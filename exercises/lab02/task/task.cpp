#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 1e9;

void readInput(int &a, int &b, int &c, int &d) {
  ios::sync_with_stdio(0);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  cin >> a >> b >> c >> d;
  // for (int i = 0; i < a; ++i) {
  //   vector <int> temp;
  //   for (int j = 0; j < b; ++j) {
  //     int t = 0;
  //     cin >> t;
  //     temp.push_back(t);
  //   }
  //   v.push_back(temp);
  // }
}

int main() {
  // vector <vector <int>> a;
  int n, k, p, q;
  int u, v;
  int realIndex = 0;
  bool isValid = true;
  readInput(n, k, p, q);

  if (q % 2 == 0) {
    realIndex = p * 2;
  }
  else {
    realIndex = p * 2 - 1;
  }
  int tempFront = realIndex - k;
  int tempBack = realIndex + k;
  if (tempFront >= 1) {
    u = tempFront / 2 + 1;
    if (tempFront % 2 == 0) {
      v = 2;
    }
    else {
      v = 1;
    }
  }
  else if (tempBack <= n) {
    u = tempBack / 2;
    if (tempBack % 2 == 0) {
      v = 2;
    }
    else {
      v = 1;
    }
  }
  else {
    isValid = false;
  }
  if (isValid) {
    cout << u << ' ' << v;
  }
  else {
    cout << -1;
  }
  // for (int i = 0; i < n; ++i) {
  //   for (int j = 0; j < m; ++j) {
  //     cout << a[i][j] << ' ';
  //   }
  //   cout << endl;
  // }

  return 0;
}