#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)

template <typename V> void printall(const V &v) {
  for (auto it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int q;
  cin >> q;
  ll n = 1048576;

  vector<ll> A(n, -1);
  set<ll> M;
  rep(i, n) M.insert(i);

  rep(i, q) {
    ll t, x;
    cin >> t >> x;

    if (t == 2) {
      cout << A[x % n] << endl;
      continue;
    }

    if (A[x % n] == -1) {
      A[x % n] = x;
      M.erase(x % n);
      continue;
    }

    // Find the next marker to the right.
    auto it = upper_bound(M.begin(), M.end(), x % n);
    if (it == M.end()) {
      it = M.begin();
    }

    ll idx = *it;
    A[idx] = x;
    M.erase(idx);
  }
}
