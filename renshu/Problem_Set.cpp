#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  unordered_map<ll, int> cnt;
  rep(i, n) {
    ll a;
    cin >> a;
    cnt[a]++;
  }

  int m;
  cin >> m;
  rep(i, m) {
    ll a;
    cin >> a;
    if (!cnt[a]) {
      cout << "NO\n";
      return 0;
    }
    cnt[a]--;
  }

  cout << "YES\n";

  return 0;
}
