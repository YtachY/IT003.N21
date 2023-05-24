#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;
int main() {
  double n;
  ostringstream x;
  cin >> n;
  // x << setprecision(2) << fixed << n;
  x << setprecision(2) << n;
  cout << n << endl;
  // cout << n << endl;
  cout << n << setprecision(2) << fixed << endl;
  cout << " --- X PART ---" << endl;
  cout << x.str();
  return 0;
}