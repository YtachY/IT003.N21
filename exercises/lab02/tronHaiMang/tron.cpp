/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
###End banned keyword*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// ###INSERT CODE HERE -
void merge(int a[], int n, int b[], int m, int c[]) {
  int i = 0;
  int j = 0;
  int k = 0;
  while (k < m + n) {
    while (i < n) {
      if (j == m) {
        c[k] = a[i];
      } else if (a[i] <= b[j]) {
        c[k] = a[i];
      } else {
        break;
      }
      ++i;
      ++k;
    }
    while (j < m) {
      if (i == n) {
        c[k] = b[j];
      } else if (b[j] <= a[i]) {
        c[k] = b[j];
      } else {
        break;
      }
      ++j;
      ++k;
    }
  }
}
void printArray(int *a, int n) {
  for (int i = 0; i < n; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
}

int main() {
  cin.tie(0);
  std::ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, m;
  int t;
  cin >> t;
  while (cin >> n >> m || t > 0) {
    t--;
    int *a = new int[n], *b = new int[m], *c = new int[n + m];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    merge(a, n, b, m, c);
    int nc = n + m;
    for (int i = 0; i < nc; i++) {
      cout << c[i] << " ";
    }

    // printArray(c, nc);
    // printArray(a, n);
    // printArray(b, m);

    delete[] c;
    delete[] a;
    delete[] b;
  }
}
