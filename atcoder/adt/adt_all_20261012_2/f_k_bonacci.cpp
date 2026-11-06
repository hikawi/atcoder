#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

ll mod = 1000000000;

ll safe_add(ll a, ll b) {
  a %= mod;
  b %= mod;
  if (a >= mod - b) {
    return a - (mod - b);
  }
  return a + b;
}

ll safe_sub(ll a, ll b) {
  a %= mod;
  b %= mod;
  return (a - b + mod) % mod;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll n, k;
  cin >> n >> k;
  if (n < k) {
    cout << 1 << "\n";
    return 0;
  }

  vector<ll> A(k, 1);
  A.resize(n + 1, 0);
  vector<ll> S(n + 1, 0);

  A[k] = k;
  S[0] = 1;
  for (int i = 1; i < k; i++)
    S[i] = S[i - 1] + 1;
  S[k] = S[k - 1] + k;

  for (int i = k + 1; i <= n; i++) {
    A[i] = safe_sub(S[i - 1], S[i - k - 1]);
    S[i] = safe_add(A[i], S[i - 1]);
  }

  // for (const auto a : S)
  //   cout << a << "\n";
  cout << A[n];

  return 0;
}
