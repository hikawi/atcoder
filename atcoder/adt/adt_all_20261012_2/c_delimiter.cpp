#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  vector<ll> A;
  while (true) {
    ll a;
    cin >> a;
    A.push_back(a);
    if (a == 0)
      break;
  }

  for (const auto a : A | views::reverse)
    cout << a << "\n";

  return 0;
}
