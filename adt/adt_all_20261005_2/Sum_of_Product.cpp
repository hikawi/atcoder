#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<ll> A(n);
  rep(i, n) cin >> A[i];

  vector<ll> P(n);
  P[n - 1] = A[n - 1];
  for (int i = n - 2; i >= 0; i--)
    P[i] = P[i + 1] + A[i];

  ll sop = 0;
  rep(i, n - 1) {
    sop += (A[i] * P[i + 1]);
  }

  cout << sop << endl;

  return 0;
}
