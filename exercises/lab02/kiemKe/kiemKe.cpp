#include <iostream>
#include <string>
using namespace std;

void heapify(double arr[], int n, int i) {
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

void heapSort(double arr[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  for (int i = n - 1; i >= 0; i--) {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

void quickSort(double* a, int b, int e) {
  if (b >= e) return;
  double Pivot = a[(b + e) / 2];
  int i = b, j = e;
  while (i < j) {
    while (a[i] < Pivot) i++;
    while (a[j] > Pivot) j--;
    if (i <= j) {
      swap(a[i], a[j]);
      i++;
      j--;
    }
  }
  quickSort(a, b, j);
  quickSort(a, i, e);
}

int main() {
  ios::sync_with_stdio(0);
  freopen("input.txt", "r", stdin);
  int n;
  cin >> n;
  if (n == 0) {
    cout << 0;
    return 0;
  }
  double* A = new double[n];
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  // quickSort(A, 0, n - 1);
  heapSort(A, n);
  double X = A[0];
  int dem = 1;
  for (int i = 0; i < n; i++)
    if (A[i] != X) {
      dem++;
      X = A[i];
    }
  delete (A);
  cout << dem;
  return 0;
}