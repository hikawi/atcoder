#include <bits/stdc++.h>
using namespace std;

bool ispalin(string &a) {
  int i = 0;
  int j = a.length() - 1;
  while (i < j) {
    if (a[i++] == a[j--]) {
      continue;
    }
    return false;
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  vector<string> strs;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    strs.push_back(s);
  }

  string out = "No";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j)
        continue;
      string s = strs[i] + strs[j];
      if (ispalin(s)) {
        out = "Yes";
        break;
      }
    }
  }

  cout << out << endl;
}
