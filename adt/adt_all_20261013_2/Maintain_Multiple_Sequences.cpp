#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, q;
  cin >> n >> q;

  vector<vector<int>> A(n);
  rep(i, n) {
    int l;
    cin >> l;
    A[i].resize(l);
    rep(j, l) cin >> A[i][j];
  }

  rep(qi, q) {
    int s, t;
    cin >> s >> t;
    cout << A[--s][--t] << "\n";
  }

  return 0;
}
