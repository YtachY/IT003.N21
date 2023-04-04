#include <iostream>
#include <vector>

using namespace std;

#include <iostream>

void heapify(int arr[], int n, int i) {
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < n && arr[l] > arr[largest])
    largest = l;

  if (r < n && arr[r] > arr[largest])
    largest = r;

  if (largest != i) {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

void heapSort(int arr[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  for (int i = n - 1; i >= 0; i--) {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}
void printArray(int arr[], int n) {
  for (int i = 0; i < n; ++i) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}
int main() {
  freopen("input.txt", "r", stdin);
  int n = 0, result = -1;
  cin >> n;
  if (n <= 0) {
    result = 0;
  } else {
    int *a = new int[n];
    int temp[n];

    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      temp[i] = 0;
    }

    heapSort(a, n);

    for (int i = 0; i < n; ++i) {
      if (a[i] < n) {
        ++temp[a[i]];
      }
    }
    printArray(a, n);
    printArray(temp, n);

    delete[] a;
    for (int i = 0; i < n; ++i) {
      if (temp[i] == 0) {
        result = i;
        break;
      }
      if (i == n - 1) {
        result = n;
      }
    }
  }
  if (result > -1) {
    cout << result;
  }
  return 0;
}