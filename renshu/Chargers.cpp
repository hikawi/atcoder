#include <algorithm>
#include <ios>
#include <iostream>
#include <set>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll q, v;
  cin >> q >> v;
  set<pair<ll, ll>> S;

  rep(qi, q) {
    int i;
    cin >> i;
    if (i == 1) {
      ll t, w;
      cin >> t >> w;
      S.emplace(t, w);
    } else {
      ll t;
      cin >> t;

      auto it = max_element(S.begin(), S.end(), [&](const auto a, const auto b) {
        ll da = min(a.second + (t - a.first), v);
        ll db = min(b.second + (t - b.first), v);
        return da < db;
      });
      if (it == S.end()) {
        cout << "-1\n";
      } else {
        cout << min(it->second + (t - it->first), v) << "\n";
        S.erase(it);
      }
    }
  }
}
