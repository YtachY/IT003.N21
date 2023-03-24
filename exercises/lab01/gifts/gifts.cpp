#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void read(int &n, int &x, vector<int> &a) {
  ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  cin >> n >> x;
  for (int i = 0; i < n; ++i) {
    int temp;
    cin >> temp;
    a.push_back(temp);
  }
}

int main() {
  int n, x, result = 0;
  vector<int> a;

  read(n, x, a);
  sort(a.begin(), a.end());
  int i = 0;
  int j = n - 1;
  while (i < j) {
    int temp = a[i] + a[j];
    if (temp <= x) {
      result = max(result, temp);
      ++i;
    }
    else {
      --j;
    }
  }
  // for (auto i: a) {
  //   cout << endl << i << " ";
  // }
  cout << result;
  return 0;
}