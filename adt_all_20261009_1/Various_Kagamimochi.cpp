#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  cin >> n;
  vector<ll> A(n);
  rep(i, n) cin >> A[i];

  ll s = 0;
  for (auto it = A.begin(); it != A.end(); it++) {
    auto up = upper_bound(A.begin(), it, *it / 2);
    s += (up - A.begin());
  }

  cout << s << endl;

  return 0;
}
