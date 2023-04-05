#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<int> v) {
  for (auto i : v) {
    cout << i << ' ';
  }
  cout << "\n";
}

void readInput(vector<int> &v, int n) {
  ios::sync_with_stdio(0);
  // freopen("input.txt", "r", stdin);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    v.push_back(t);
  }
}

int findMex(vector<int> arr) {
  int result = 0;
  vector<int> present(arr.size() + 1, 0);  // initialize a vector to mark presence of integers

  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] >= 0 && arr[i] <= arr.size()) {
      ++present[arr[i]];  // mark the presence of integer in the boolean vector
    }
  }

  for (int i = 0; i < present.size(); i++) {
    if (!present[i]) {
      result = i;
      break;  // return the minimum non-negative integer that is not present in the vector
    }
    if (i == present.size() - 1) {
      result = present.size();  // if all integers are present, return the size of the boolean vector
    }
  }
  printArray(present);
  return result;
}

int main() {
  int n;
  int result = 0;
  vector<int> a;
  readInput(a, n);

  result = findMex(a);

  // printArray(a);
  cout << result;
  return 0;
}