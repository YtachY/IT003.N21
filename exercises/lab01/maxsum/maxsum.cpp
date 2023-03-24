#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>

using namespace std;

const int MAX = 1e9;

int main() {

  // ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int n =0, minusSum = 0, plusSum = 0, maxMinus = 0, result = 0;
  int minPlus = MAX;
  vector<int> a;
  // vector<int> minusArray;
  // vector<int> plusArray;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int temp;
    cin >> temp;
    if (i % 2 != 0) {
      if (maxMinus < temp) {
        maxMinus = temp;
      }
      minusSum += temp;
      // minusArray.push_back(temp);
    }
    else {
      if (minPlus > temp) {
        minPlus = temp;
      }
      plusSum += temp;
      // plusArray.push_back(temp);
    }
    a.push_back(temp);
  }
  result = (plusSum - minPlus + maxMinus) - (minusSum - maxMinus + minPlus);
  cout << result;

  // for (auto &i: a) {
  //   cout << i << endl;
  // }
  return 0;
}