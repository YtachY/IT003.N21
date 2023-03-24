// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <string>

#include <bits/stdc++.h>

using namespace std;

bool isValid(string s, vector<char> unacceptableCharacters) {
  bool result = true;
  for (char i: unacceptableCharacters) {
    for (int j = 0; j < s.size(); ++j) {
      if (s[j] == i) {
        result = false;
        break;
      }
    }
  }
  return result;
}
bool isAnyUpperIn(string s) {
  bool result = false;
  for (char i: s) {
    if (isupper(i)) {
      result = true;
      break;
    }
  }
  return result;
}
int amountOfSymbolsCharactersIn(string s, vector<char> symbolsCharacters) {
  int result = 0;
  for (char i: symbolsCharacters) {
    for (int j = 0; j < s.size(); ++j) {
      if (s[j] == i) {
        ++result;
      }
    }
  }
  return result;
}
int amountOfNumbersCharactersIn(string s) {
  int result = 0;
  for (char c: s) {
    if (isdigit(c)) {
      ++result;
    }
  }
  return result;
}
int amountOfUpperCharactersIn(string s) {
  int result = 0;
  for (char c: s) {
    if (isupper(c)) {
      ++result;
    }
  }
  return result;
}
bool isAllNumberIn(string s) {
  bool result = true;
  for (char c: s) {
    if (!isdigit(c)) {
      result = false;
      break;
    }
  }
  return result;
}
bool isAllLowerCharactersIn(string s) {
  return !isAnyUpperIn(s);
}
bool isNumberIn(string s) {
  bool result = false;
  for (char c: s) {
    if (isdigit(c)) {
      result = true;
      break;
    }
  }
  return result;
}
bool isSpecialCharacterIn(string s, vector<char> symbolsCharacters) {
  bool result = false;
  for (char i: symbolsCharacters) {
    for (int j = 0; j < s.size(); ++j) {
      if (s[j] == i) {
        result = true;
        break;
      }
    }
  }
  return result;
}

int assess(string pass) {
  vector<char> symbolsCharacters{ '!', '@', '#', '$', '%', '^', '&', '*', '?', '_', '~'};
  int score = 0;
  int BaseScore = 40;
  int Bonus_Excess = 3;
  int Bonus_Upper = 4;
  int Bonus_Number = 5;
  int Bonus_Symbols = 5;
  int Bonus_Combo = 0;
  int Bonus_FlatLower = 0;
  int Bonus_FlatNumber = 0;
  int Number_Upper = 0;
  int Number_Execess = 0;
  int Number_Numbers = 0;
  int Number_Symbols = 0;
  // count Bonus_Combo score
  if (isAnyUpperIn(pass) && isSpecialCharacterIn(pass, symbolsCharacters) && isNumberIn(pass)) {
    Bonus_Combo = 25;
  }
  else if (isAnyUpperIn(pass) && isSpecialCharacterIn(pass, symbolsCharacters)
          || isSpecialCharacterIn(pass, symbolsCharacters) && isNumberIn(pass)
          || isAnyUpperIn(pass) && isNumberIn(pass)) {
    Bonus_Combo = 15;
  }
  // count Bonus_FlatLower
  if (isAllLowerCharactersIn(pass)) {
    Bonus_FlatLower = -15;
  }
  // count Bonus_FlatNumber
  if (isAllNumberIn(pass)) {
    Bonus_FlatNumber = -35;
  }
  // count Number_Execess
  Number_Execess = pass.size() - 8;
  // count Number_Upper
  Number_Upper = amountOfUpperCharactersIn(pass);
  // count Number_Numbers
  Number_Numbers = amountOfNumbersCharactersIn(pass);
  // count Number_Symbols
  Number_Symbols = amountOfSymbolsCharactersIn(pass,symbolsCharacters);
  
  // cout << "Bonus_Combo: " << Bonus_Combo << endl;
  // cout << "Bonus_FlatLower: " << Bonus_FlatLower << endl;
  // cout << "Bonus_FlatNumber: " << Bonus_FlatNumber << endl;
  // cout << "Number_Upper: " << Number_Upper << endl;
  // cout << "Number_Execess: " << Number_Execess << endl;
  // cout << "Number_Numbers: " << Number_Numbers << endl;
  // cout << "Number_Symbols: " << Number_Symbols << endl;
  score = BaseScore + (Number_Execess * Bonus_Excess) + (Number_Upper * Bonus_Upper) + (Number_Numbers * Bonus_Number) + (Number_Symbols * Bonus_Symbols) + Bonus_Combo + Bonus_FlatLower + Bonus_FlatNumber;
  return score;
}

int main() {
  ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  vector<char> unacceptableCharacters{ '.','\\','/','"', '\''};
  string pass;
  int score = 0;
  cin >> pass;

  if (!isValid(pass, unacceptableCharacters)) {
    cout << "KhongHopLe";
  }
  else {
    score = assess(pass);
    // cout << score << "\n";
    if (score < 50) {
      cout << "Yeu";
    }
    else if (50 <= score && score < 75) {
      cout << "Vua";
    }
    else if (75 <= score && score < 100) {
      cout << "Manh";
    }
    else {
      cout << "RatManh";
    }
    cout << "\n";
  }
  return 0;
}