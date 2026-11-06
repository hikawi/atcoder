#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

vector<ll> L, R;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, q;
  cin >> n >> q;
  L = vector<ll>(n);
  R = vector<ll>(n);
  for (int i = 1; i < n; i++)
    cin >> L[i];
  for (int i = 0; i < n - 1; i++)
    cin >> R[i];

  vector<ll> minL(n), minR(n);
  // R min from start
  for (int i = 0; i < n; i++) {
    if (i == 0)
      minR[i] = R[i];
    else
      minR[i] = min(minR[i - 1], R[i]);
  }
  // L min from end
  for (int i = n - 1; i >= 0; i--) {
    if (i == n - 1)
      minL[i] = L[i];
    else
      minL[i] = min(minL[i + 1], L[i]);
  }

  rep(qi, q) {
    ll s, t;
    cin >> s >> t;

    ll direct = LONG_LONG_MAX, indirect = LONG_LONG_MAX;
    if (s < t) {
      // we want to move right
      direct = R[s - 1];
      // or can we hop to the left?
      if (s > 1)
        indirect = L[s - 1] + minR[s - 1];
    } else {
      // we want to move left
      direct = L[s - 1];
      // or can we detour?
      if (s < n)
        indirect = R[s - 1] + minL[s];
    }

    cout << min(direct, indirect) << "\n";
  }

  return 0;
}
