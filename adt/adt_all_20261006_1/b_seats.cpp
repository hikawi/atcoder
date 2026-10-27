#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  string s;
  cin >> s;

  int c = 0;
  for (int i = 0; i < n - 2; i++) {
    if (s[i] == '#' && s[i + 2] == '#' && s[i + 1] == '.')
      c++;
  }
  cout << c << endl;

  return 0;
}
