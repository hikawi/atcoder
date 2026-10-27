#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  rep(i, t) {
    int n;
    cin >> n;

    int c = 0;
    rep(j, n) {
      ll k;
      cin >> k;
      c += (k % 2 == 1);
    }

    cout << c << endl;
  }

  return 0;
}
