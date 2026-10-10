#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  int c = 0;
  for (int i = 1; i < s.length(); i++) {
    if (i == s.length() - 1) {
      cout << c << endl;
      break;
    }

    if (s[i] == '|') {
      cout << c << " ";
      c = 0;
    } else {
      c++;
    }
  }
}
