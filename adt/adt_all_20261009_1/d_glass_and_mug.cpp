#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int k, g, m;
  cin >> k >> g >> m;

  int G = 0, M = 0;
  rep(ki, k) {
    if (G == g) {
      G = 0;
    } else if (M == 0) {
      M = m;
    } else {
      int over = min(g - G, M);
      M -= over;
      G += over;
    }
  }

  cout << G << " " << M << endl;

  return 0;
}
