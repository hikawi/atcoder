#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  cout << (s[0] - '0') * (s[2] - '0') << endl;

  return 0;
}
