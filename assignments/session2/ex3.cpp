#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point
{
  float x, y;
};

float distance(Point p1, Point p2)
{
  float dx = p1.x - p2.x;
  float dy = p1.y - p2.y;
  return sqrt(dx * dx + dy * dy);
}

float minDistance(Point p, vector<Point> A)
{
  float minDist = INFINITY;
  for (Point point : A)
  {
    float dist = distance(p, point);
    if (dist < minDist)
    {
      minDist = dist;
    }
  }
  return minDist;
}

int main()
{
  Point p = {3, 4};
  vector<Point> A = {{1, 2}, {4, 6}, {8, 1}, {2, 9}};
  cout << minDistance(p, A) << endl;
  return 0;
}