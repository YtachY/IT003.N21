#include <algorithm>
#include <iostream>

#define ll long long
using namespace std;

int countDistinct(ll arr[], int n) {
  // First sort the array so that all
  // occurrences become consecutive
  sort(arr, arr + n);

  // Traverse the sorted array
  int res = 0;
  for (int i = 0; i < n; i++) {
    // Move the index ahead while
    // there are duplicates
    while (i < n - 1 && arr[i] == arr[i + 1])
      i++;
    res++;
  }

  return res;
}

// Driver program to test above function
int main() {
  ll arr[] = {6, 10, 5, 4, 9, 120, 4, 6, 10};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << countDistinct(arr, n);
  return 0;
}