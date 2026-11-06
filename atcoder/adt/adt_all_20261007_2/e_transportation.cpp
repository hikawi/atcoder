#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll n, m;
  cin >> n >> m;
  vector<ll> A(n);
  ll sum = 0;
  rep(i, n) {
    cin >> A[i];
    sum += A[i];
  }

  if (m >= sum) {
    cout << "infinite\n";
    return 0;
  }

  // また二分探索？？？
  ll lo = 0, hi = m;
  while (lo <= hi) {
    ll mid = (lo + hi) / 2;
    ll s = 0;
    for (const auto a : A) {
      s += min(mid, a);
    }

    if (s > m) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }

  cout << hi << endl;

  return 0;
}
