#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll x;
  cin >> x;

  cout << ((x < 0 && x % 10 != 0) ? (x / 10 - 1) : (x / 10)) << endl;
  return 0;
}
