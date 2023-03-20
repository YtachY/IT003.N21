#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void NhapDS(vector<int> &v)
{
  int tmp;
  cout << "Nhap danh sach" << endl;
  cin >> tmp;
  while (tmp > 0)
  {
    v.push_back(tmp);
    cin >> tmp;
  }
}

void InDS(vector<int> v)
{
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << ' ';
  cout << endl;
}

void Top5(vector<int> v)
{
  sort(v.begin(), v.end());
  if (v.size() < 5)
  {
    cout << "DS khong co du 5 phan tu" << endl;
    return;
  }
  for (vector<int>::iterator i = v.end() - 1; i > v.end() - 6; i--)
    cout << *i << ' ';
}

int TimK(vector<int> v, int k)
{
  vector<int>::iterator i;
  i = find(v.begin(), v.end(), k);
  if (i != v.end())
    return i - v.begin();
  return -1;
}

int main()
{
  vector<int> A;
  int k;
  NhapDS(A);
  cout << "Danh sach da nhap: ";
  InDS(A);
  cout << "Gia tri can tim k = ";
  cin >> k;
  cout << TimK(A, k) << endl;
  Top5(A);
  return 0;
}
