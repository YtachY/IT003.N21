#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX = 1e9;

void heapify(vector<int>& v, int n, int i) {
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

void heapSort(vector<int>& v) {
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

void printArray(vector<int> v, int n) {
  for (int i = 0; i < n; ++i) {
    cout << v[i] << ' ';
  }
  cout << endl;
}
void readInput(vector<int>& v, int& n, int& k) {
  ios::sync_with_stdio(0);
  freopen("input.txt", "r", stdin);

  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    int temp = 0;
    cin >> temp;
    v.push_back(temp);
  }
}

int main() {
  int n, k;
  int totalDiff = 1;
  vector<int> myArray;
  vector<int> result;
  readInput(myArray, n, k);

  heapSort(myArray);
  // printArray(myArray, n);

  for (int i = 1; i < myArray.size(); ++i) {
    if (myArray[i] > myArray[i - 1]) {
      totalDiff++;
    }
  }
  // cout << "totalDiff: " << totalDiff << endl;
  int dup = k - totalDiff;
  int j = 1;
  result.push_back(myArray[0]);
  for (int i = 0; i < n; ++i) {
    if (result.size() == k) {
      break;
    } else if (myArray[j] > myArray[j - 1]) {
      result.push_back(myArray[j]);
    } else if (dup > 0) {
      result.push_back(myArray[j]);
      --dup;
    }
    ++j;
  }
  printArray(result, k);
  return 0;
}