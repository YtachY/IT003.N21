#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int sortedArray[], int x);

int main() {
  int a[] = {19, 18, 17, 16, 15, 14, 13};
  int index = binarySearch(a, 14);
  cout << "Find" << 4 << "At: a[" << index << "]\n";
  return 0;
}

int binarySearch(int sortedArray[], int n, int x)
{
  int l = 0;
  int r = n - 1;
  while (l <= r) {
    m = (l + r) / 2;
    if (x == sortedArray[m]) {
      return m;
    }
    if (x < sortedArray[m]) {
      l = m + 1;
    }
    else {
      r = m - 1;
    }
  }
  return -1;
}
