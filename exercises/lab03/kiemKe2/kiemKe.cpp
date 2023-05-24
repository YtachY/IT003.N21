#include <iostream>
#include <vector>

using namespace std;

bool cmp(string a, string b) {
  if (a.size() == b.size()) {
    return a > b;
  } else {
    return a.size() > b.size();
  }
}
bool cmpPair(pair<string, int> a, pair<string, int> b) {
  if (a.second == b.second) {
    return cmp(a.first, b.first);
  } else {
    return a.second < b.second;
  }
}
void heapifyPair(vector<pair<string, int>>& v, int n, int i, bool (*cmp)(pair<string, int>, pair<string, int>)) {
  int largest = i;        // Initialize largest as root
  int left = 2 * i + 1;   // left child index
  int right = 2 * i + 2;  // right child index

  // If left child is larger than root
  if (left < n && cmp(v[left], v[largest]))
    largest = left;

  // If right child is larger than largest so far
  if (right < n && cmp(v[right], v[largest]))
    largest = right;

  // If largest is not root
  if (largest != i) {
    swap(v[i], v[largest]);

    // Recursively heapify the affected sub-tree
    heapifyPair(v, n, largest, cmp);
  }
}

void heapPair(vector<pair<string, int>>& v, bool (*cmp)(pair<string, int>, pair<string, int>)) {
  int n = v.size();

  // Build max heap
  for (int i = n / 2 - 1; i >= 0; i--)
    heapifyPair(v, n, i, cmp);

  // Extract elements from heap one by one
  for (int i = n - 1; i >= 0; i--) {
    swap(v[0], v[i]);

    // Call max heapify on the reduced heap
    heapifyPair(v, i, 0, cmp);
  }
}
void heapify(vector<string>& v, int n, int i, bool (*cmp)(string, string)) {
  int largest = i;        // Initialize largest as root
  int left = 2 * i + 1;   // left child index
  int right = 2 * i + 2;  // right child index

  // If left child is larger than root
  if (left < n && cmp(v[left], v[largest]))
    largest = left;

  // If right child is larger than largest so far
  if (right < n && cmp(v[right], v[largest]))
    largest = right;

  // If largest is not root
  if (largest != i) {
    swap(v[i], v[largest]);

    // Recursively heapify the affected sub-tree
    heapify(v, n, largest, cmp);
  }
}

void heap(vector<string>& v, bool (*cmp)(string, string)) {
  int n = v.size();

  // Build max heap
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(v, n, i, cmp);

  // Extract elements from heap one by one
  for (int i = n - 1; i >= 0; i--) {
    swap(v[0], v[i]);

    // Call max heapify on the reduced heap
    heapify(v, i, 0, cmp);
  }
}
void printVector(vector<string> v) {
  for (auto i : v) {
    cout << i << ' ';
  }
}
void printVector(vector<pair<string, int>> v) {
  for (auto i : v) {
    cout << i.first << ' ' << i.second << "\n";
  }
}

int main() {
  ios::sync_with_stdio(0);
  freopen("input.txt", "r", stdin);

  int n;
  vector<pair<string, int>> result;
  vector<string> nhap;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string temp;
    cin >> temp;
    nhap.push_back(temp);
  }

  heap(nhap, cmp);

  pair<string, int> temp(nhap[0], 1);

  for (int i = 1; i < nhap.size(); ++i) {
    // cout << temp.first << " " << temp.second << endl;
    if (nhap[i] != temp.first) {
      // cout << ">>> PUSH";
      result.push_back(temp);
      temp.second = 1;
    } else {
      ++temp.second;
    }
    temp.first = nhap[i];
  }
  result.push_back(temp);

  heapPair(result, cmpPair);

  // cout << "----NHAP" << endl;
  // printVector(nhap);
  // cout << "----RESULT" << endl;
  printVector(result);
  return 0;
}