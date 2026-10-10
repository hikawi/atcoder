#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string s, t;
  cin >> n >> s >> t;

  int c = 0;
  rep(i, n) {
    if (s[i] != t[i])
      c++;
  }
  cout << c << endl;

  return 0;
}
