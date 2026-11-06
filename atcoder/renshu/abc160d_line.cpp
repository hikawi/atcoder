#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, x, y;
  cin >> n >> x >> y;
  x--;
  y--;

  vector<int> dist(n);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      // don't pass xy
      int noxy = abs(j - i);

      // with xy, so its
      int xy1 = abs(x - i) + 1 + abs(y - j);
      int xy2 = abs(x - j) + 1 + abs(y - i);

      int shortest = min(noxy, min(xy1, xy2));
      dist[shortest]++;
    }
  }

  for (int i = 1; i < n; i++)
    cout << dist[i] << "\n";

  return 0;
}
