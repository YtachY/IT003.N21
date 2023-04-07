#include <iostream>
#include <string>
#include <vector>

#define ll long long
using namespace std;

const int MAX = 5e4;

void heapify(vector<ll>& v, int n, int i) {
  int largest = i;        // Initialize largest as root
  int left = 2 * i + 1;   // left child index
  int right = 2 * i + 2;  // right child index

  // If left child is larger than root
  if (left < n && v[left] > v[largest])
    largest = left;

  // If right child is larger than largest so far
  if (right < n && v[right] > v[largest])
    largest = right;

  // If largest is not root
  if (largest != i) {
    swap(v[i], v[largest]);

    // Recursively heapify the affected sub-tree
    heapify(v, n, largest);
  }
}

void heapSort(vector<ll>& v) {
  int n = v.size();

  // Build max heap
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(v, n, i);

  // Extract elements from heap one by one
  for (int i = n - 1; i >= 0; i--) {
    swap(v[0], v[i]);

    // Call max heapify on the reduced heap
    heapify(v, i, 0);
  }
}

void readInput(vector<ll>& v, int n) {
  ios::sync_with_stdio(0);
  // freopen("input.txt", "r", stdin);

  cin >> n;

  for (int i = 0; i < n; ++i) {
    ll temp = 0;
    cin >> temp;
    v.push_back(temp);
  }
}
void printArray(vector<ll> v) {
  for (int i = 0; i < v.size(); ++i) {
    cout << v[i] << ' ';
  }
}

int main() {
  int n;
  int result = 0;
  vector<ll> myArray;
  readInput(myArray, n);

  heapSort(myArray);

  for (int i = 0; i < myArray.size(); ++i) {
    // if (myArray[i] > myArray[i - 1]) {
    //   ++result;
    // }
    while (i < myArray.size() && myArray[i] == myArray[i + 1])
      i++;

    result++;
  }
  cout << result;
  // printArray(myArray);
  return 0;
}