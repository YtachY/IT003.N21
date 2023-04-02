#include <iostream>
#include <vector>

using namespace std;

struct Point2D {
  int x;
  int y;
};

bool comparePoint2D(Point2D a, Point2D b) {
  if (a.x == b.x) {
    return a.y > b.y;
  }
  return a.x < b.x;
}

void merge(vector<Point2D> &arr, int left, int mid, int right, bool (*compare)(Point2D, Point2D)) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  vector<Point2D> L(n1), R(n2);

  for (int i = 0; i < n1; i++) {
    L[i] = arr[left + i];
  }
  for (int j = 0; j < n2; j++) {
    R[j] = arr[mid + 1 + j];
  }

  int i = 0, j = 0, k = left;

  while (i < n1 && j < n2) {
    if (compare(L[i], R[j])) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(vector<Point2D> &arr, int left, int right, bool (*compare)(Point2D, Point2D)) {
  if (left >= right) {
    return;
  }
  int mid = left + (right - left) / 2;
  mergeSort(arr, left, mid, compare);
  mergeSort(arr, mid + 1, right, compare);
  merge(arr, left, mid, right, compare);
}

void readInput(int &a, vector<Point2D> &v) {
  ios::sync_with_stdio(0);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  cin >> a;

  for (int i = 0; i < a; ++i) {
    Point2D temp;
    cin >> temp.x >> temp.y;
    v.push_back(temp);
  }
}

int main() {
  // vector<Point2D> arr = {{5, 2}, {9, 3}, {3, 6}, {2, 1}, {8, 4}};
  vector<Point2D> arr;
  int n;
  readInput(n, arr);
  mergeSort(arr, 0, arr.size() - 1, comparePoint2D);

  for (int i = 0; i < arr.size(); i++) {
    // cout << "(" << arr[i].x << ", " << arr[i].y << ") ";
    cout << arr[i].x << " " << arr[i].y << "\n";
  }

  // mergeSort(arr, 0, arr.size() - 1, compareY);

  // for (int i = 0; i < arr.size(); i++) {
  //     cout << "(" << arr[i].x << ", " << arr[i].y << ") ";
  // }
  // cout << endl;

  return 0;
}