#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

bool confusing(int h, int m) {
  int nh = (h / 10) * 10 + m / 10;
  int nm = (h % 10) * 10 + m % 10;
  return nh >= 0 && nh <= 23 && nm >= 0 && nm <= 59;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int h, m;
  cin >> h >> m;

  while (!confusing(h, m)) {
    m++;
    if (m >= 60) {
      m = 0;
      h++;
    }
    if (h >= 24) {
      h = 0;
    }
  }

  cout << h << " " << m << "\n";

  return 0;
}
