#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;

  if (s == t) {
    cout << "Yes" << endl;
    return 0;
  }

  for (int i = 0; i < s.length() - 1; i++) {
    string n = s;
    n[i] = s[i + 1];
    n[i + 1] = s[i];
    if (n == t) {

      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No\n";
}
