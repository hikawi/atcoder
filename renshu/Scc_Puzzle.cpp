#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll n, m;
  cin >> n >> m;

  if (m <= 2 * n) {
    cout << min(n, m / 2) << "\n";
    return 0;
  }

  ll sure = n;
  m -= 2 * n;
  n = 0;
  sure += m / 4;
  cout << sure << "\n";

  return 0;
}
