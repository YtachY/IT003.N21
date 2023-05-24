// #include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
using namespace std;

struct DONTHUC {
  int somu;
  double heso;

  DONTHUC(double _heso = 0, int _somu = 0) {
    heso = _heso;
    somu = _somu;
  }

  DONTHUC& operator=(const DONTHUC& rhs) {
    if (this == &rhs) return *this;
    this->heso = rhs.heso;
    this->somu = rhs.somu;
    return *this;
  }
};

struct Node {
  DONTHUC* data;
  Node* next;

  Node(DONTHUC* _data = nullptr) {
    this->data = _data;
    this->next = nullptr;
  }
};

struct DATHUC {
  Node* head;
  Node* tail;
  DATHUC() {
    this->head = nullptr;
    this->tail = nullptr;
  }
};

// ###INSERT CODE HERE -
void XuatF(DATHUC da) {
  Node* i = da.head;
  while (i) {
    DONTHUC* don = i->data;
    cout << "\nHe so: " << don->heso << "\tSomu: " << don->somu << endl;
    i = i->next;
  }
}

double sqr(double x) {
  return x * x;
}

double pow(double a, int b) {
  if (b == 0)
    return 1;
  else if (b % 2 == 0)
    return sqr(pow(a, b / 2));
  else
    return a * (sqr(pow(a, b / 2)));
}
void Nhap(DATHUC& da, double heso, int somu) {
  // da = DATHUC();
  DONTHUC* don = new DONTHUC(heso, somu);
  Node* temp = new Node(don);
  if (!da.tail) {
    da.head = temp;
    da.tail = da.head;
  } else {
    da.tail->next = temp;
    da.tail = temp;
  }
}
double TinhDaThuc(DATHUC L, double x) {
  double S = 0;
  for (Node* i = L.head; i != NULL; i = i->next) {
    S += i->data->heso * pow(x, i->data->somu);
  }
  return S;
}
double TinhDaThuc(DATHUC da, double x) {
  Node* iterator = da.head;
  double result = 0;
  while (iterator) {
    DONTHUC* don = iterator->data;
    double tich = 1;
    while (don->somu--) {
      tich *= x;
    }
    result += tich * don->heso;
    iterator = iterator->next;
  }
  return result;
}
void XuatDonThuc(DONTHUC* don, bool& isHead, bool& isZero) {
  if (don->heso == 0) {
    return;
  }
  isZero = false;
  if (don->somu > 1) {
    if (!isHead) {
      if (don->heso == 1) {
        cout << "+x^" << don->somu;
      } else if (don->heso == -1) {
        cout << "-x^" << don->somu;
      } else if (don->heso > 0) {
        cout << "+" << don->heso << "x^" << don->somu;
      } else {
        cout << don->heso << "x^" << don->somu;
      }
    } else {
      isHead = false;
      if (don->heso == 1) {
        cout << "x^" << don->somu;
      } else if (don->heso == -1) {
        cout << "-x^" << don->somu;
      } else {
        cout << don->heso << "x^" << don->somu;
      }
    }
  } else if (don->somu == 1) {
    if (!isHead) {
      if (don->heso == 1) {
        cout << "+x";
      } else if (don->heso == -1) {
        cout << "-x";
      } else if (don->heso > 0) {
        cout << "+" << don->heso << "x";
      } else {
        cout << don->heso << "x";
      }
    } else {
      isHead = false;
      if (don->heso == 1) {
        cout << "x";
      } else if (don->heso == -1) {
        cout << "-x";
      } else {
        cout << don->heso << "x";
      }
    }
  } else {  // somu == 0
    if (!isHead) {
      if (don->heso == 1) {
        cout << "+1";
      } else if (don->heso == -1) {
        cout << "-1";
      } else if (don->heso > 0) {
        cout << "+" << don->heso;
      } else {
        cout << don->heso;
      }
    } else {
      isHead = false;
      if (don->heso == 1) {
        cout << "1";
      } else if (don->heso == -1) {
        cout << "-1";
      } else {
        cout << don->heso;
      }
    }
  }
}
void Xuat(DATHUC da) {
  bool isZero = true;
  bool isHead = true;
  for (Node* i = da.head; i; i = i->next) {
    XuatDonThuc(i->data, isHead, isZero);
  }
  if (isZero) {
    cout << 0;
  }
}

int main() {
  ios::sync_with_stdio(0);
  freopen("input.txt", "r", stdin);
  DATHUC B;
  int N;

  cin >> N;
  for (int test = 0; test < N; test++) {
    double heso;
    int somu;
    cin >> heso >> somu;
    Nhap(B, heso, somu);
  }

  cout << "Da thuc vua nhap la: ";
  Xuat(B);
  double x;
  cin >> x;
  cout << "\nVoi x=" << x << ", gia tri da thuc la: " << setprecision(2) << fixed << TinhDaThuc(B, x);
  return 0;
}
