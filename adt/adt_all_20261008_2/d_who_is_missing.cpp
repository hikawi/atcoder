#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  cin >> n;
  vector<int> A(n);
  rep(i, 4 * n - 1) {
    ll a;
    cin >> a;
    A[a - 1]++;
  }

  rep(i, n) {
    if (A[i] == 3)
      cout << i + 1 << endl;
  }

  return 0;
}
