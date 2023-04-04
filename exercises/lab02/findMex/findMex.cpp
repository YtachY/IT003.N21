#include <iostream>
#include <vector>

using namespace std;

#include <iostream>

/**
 *
 * The merge() function is used for merging two halves.
 * The merge(arr, l, m, r) is key process that assumes that
 * arr[l..m] and arr[m+1..r] are sroted and merges the two
 * sroted sub-arrays into one.
 *
 * @param arr - array with two halves arr[l...m] and arr[m+1...r]
 * @param l - left index or start index of first half array
 * @param m - right index or end index of first half array
 *
 * (The second array starts form m+1 and goes till r)
 *
 * @param r - end index or right index of second half array
 */
void merge(int *arr, int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  int *L = new int[n1], *R = new int[n2];

  for (i = 0; i < n1; i++) L[i] = arr[l + i];
  for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

  i = 0;
  j = 0;
  k = l;
  while (i < n1 || j < n2) {
    if (j >= n2 || (i < n1 && L[i] <= R[j])) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  delete[] L;
  delete[] R;
}

/**
 * Merge srot is a divide and conquer algorithm, it divides the
 * input array into two halves and calls itself for the two halves
 * and then calls merge() to merge the two halves
 *
 * @param arr - array to be sroted
 * @param l - left index or start index of array
 * @param r - right index or end index of array
 *
 */
void mergeSrot(int *arr, int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSrot(arr, l, m);
    mergeSrot(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

/**
 * Utility function used to print the array after
 * sroting
 */
void show(int *arr, int size) {
  for (int i = 0; i < size; i++) std::cout << arr[i] << " ";
  std::cout << "\n";
}
int main() {
  freopen("input.txt", "r", stdin);
  int n = 0, result = -1;
  cin >> n;
  int *a = new int[n];
  int temp[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    temp[i] = 0;
  }

  mergeSrot(a, 0, n - 1);

  for (int i = 0; i < n; ++i) {
    if (a[i] < n) {
      ++temp[a[i]];
    }
  }
  show(a, n);
  show(temp, n);

  for (int i = 0; i < n; ++i) {
    if (temp[i] == 0) {
      result = i;
      break;
    }
    if (i == n - 1) {
      result = i;
    }
  }
  if (result > -1) {
    cout << result;
  }
  delete[] a;
  return 0;
}