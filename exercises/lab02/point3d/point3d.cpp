#include <iostream>
#include <vector>
#include <algorithm>

// #include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y, z;
};


bool compare(Point p1, Point p2) {
    if (p1.x == p2.x) {
      if (p1.y == p2.y) {
        return p1.z < p2.z;
      }
      else {
        return p1.y > p2.y;
      }
    }
    return p1.x < p2.x;
}

int main() {

  ios::sync_with_stdio(false);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n;
  cin >> n;

  vector<Point> points(n);
  for (int i = 0; i < n; i++) {
    cin >> points[i].x >> points[i].y >> points[i].z;
  }

  sort(points.begin(), points.end(), compare);

  for (int i = 0; i < n; i++) {
    cout << points[i].x << " " << points[i].y << " " << points[i].z << "\n";
  }

  return 0;
}