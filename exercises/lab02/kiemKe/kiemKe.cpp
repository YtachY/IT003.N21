#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX = 5e4;

void readInput(vector<string>& v, int& n) {
  ios::sync_with_stdio(0);
  freopen("input.txt", "r", stdin);

  cin >> n;

  for (int i = 0; i < n; ++i) {
    string temp;
    cin >> temp;
    v.push_back(temp);
  }
}
void printArray(vector<string> v) {
  for (int i = 0; i < v.size(); ++i) {
    cout << v[i] << ' ';
  }
}

int countDistinct(vector<string> arr, int n) {
  int res = 1;

  // Pick all elements one by one
  for (int i = 1; i < n; i++) {
    int j = 0;
    for (j = 0; j < i; j++)
      if (arr[i] == arr[j])
        break;

    // If not printed earlier, then print it
    if (i == j)
      res++;
  }
  return res;
}

int main() {
  int n;
  int result = 1;
  bool flag = false;
  vector<string> myArray;
  readInput(myArray, n);

  // heapSort(myArray);
  result = countDistinct(myArray, n);
  cout << result << endl;
  // printArray(myArray);
  return 0;
}