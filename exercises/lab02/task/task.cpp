#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int MAX = 1e9;

pair<int, int> transferIndex(int x) {
  pair<int, int> result = {0, 0};
  if (x % 2 == 0) {
    result.first = x / 2;
    result.second = 2;
  } else {
    result.first = x / 2 + 1;
    result.second = 1;
  }
  return result;
}

int findRealIndex(int p, int q) {
  int result;
  if (q == 2) {
    result = p * 2;
  } else {
    result = p * 2 - 1;
  }
  // cout << ">>> Coordinate: " << p << ' ' << q << endl;
  // cout << ">>> RealIndex: " << result << endl;
  return result;
}
void readInput(int &a, int &b, int &c, int &d) {
  ios::sync_with_stdio(0);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  cin >> a >> b >> c >> d;
}

int main() {
  int n, k, p, q;
  int u, v;
  int realIndexAlice = 0;
  int realIndexBob = 0;
  bool isValid = true;
  pair<int, int> result = {0, 0};
  readInput(n, k, p, q);

  realIndexAlice = findRealIndex(p, q);
  realIndexBob = realIndexAlice - k;
  if (realIndexBob >= 1) {
    result = transferIndex(realIndexBob);
  } else {
    realIndexBob = realIndexAlice + k;
    if (realIndexBob <= n) {
      result = transferIndex(realIndexBob);
    } else {
      isValid = false;
    }
  }
  if (isValid) {
    cout << result.first << " " << result.second;
  } else {
    cout << -1;
  }
  return 0;
}