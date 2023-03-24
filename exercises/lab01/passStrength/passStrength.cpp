#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  vector<char> symbolsCharacters{'!', '@', '#', '$', '%', '^', '&', '*', '?', '_', '~'};
  vector<char> unacceptableCharacters{'.','\\','/','"', '\''};
  int score = 40;
  int Bonus_Excess = 3;
  int Bonus_Upper = 4;
  int Bonus_Number = 5;
  int Bonus_Symbols = 5;
  int Number_Execess = 0;
  int Number_Upper = 0;
  int Number_Numbers = 0;
  int Number_Symbols = 0;
  int Bonus_FlatNumber = 0;
  int Bonus_FlatLower = 0;
  int Bonus_Combo = 0;
  bool isValid = true;
  bool existUpper = false;
  bool existNumber = false;
  bool existSymbol = false;

  string myPass;
  cin >> myPass;

  for (char i: myPass) {
    auto temp = find(unacceptableCharacters.begin(), unacceptableCharacters.end(), i);
    if (temp != unacceptableCharacters.end()) {
      isValid = false;
      break;
    }
    ++Number_Execess;
    if (isupper(i)) {
      ++Number_Upper;
      existUpper = true;
    }
    if (isdigit(i)) {
      ++Number_Numbers;
      existNumber = true;
    }
    temp = find(symbolsCharacters.begin(), symbolsCharacters.end(), i);
    if (temp != symbolsCharacters.end()) {
      ++Number_Symbols;
      existSymbol = true;
    }
  }
  if (!isValid || Number_Execess < 8) {
    cout << "KhongHopLe";
  }
  else {
    if (Number_Numbers == Number_Execess) {
      Bonus_FlatNumber = -35;
    }
    if (Number_Upper == Number_Execess) {
      Bonus_FlatLower = -15;
    }
    if (existUpper && existNumber && existSymbol) {
      Bonus_Combo = 25;
    }
    else if (existUpper && existNumber || existSymbol && existNumber || existSymbol && existUpper) {
      Bonus_Combo = 15;
    }
    score += (Number_Execess - 8) * Bonus_Excess + (Number_Upper * Bonus_Upper) + (Number_Numbers * Bonus_Number) + (Number_Symbols * Bonus_Symbols) + Bonus_Combo + Bonus_FlatLower + Bonus_FlatNumber;
    if (score < 50) {
      cout << "Yeu";
    }
    else if (score < 75) {
      cout << "Vua";
    }
    else if (score < 100) {
      cout << "Manh";
    }
    else {
      cout << "RatManh";
    }
  }
  return 0;
}