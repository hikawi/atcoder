#include <iostream>
#include <map>
using namespace std;
using ll = long long;
int main() {
  ll n, d;
  cin >> n >> d;
  map<pair<ll, ll>, int> C;
  for (int i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    C[{x, y}]++;
  }

  ll ans = 0;
  int i = 1;
  while (i <= d) {
    auto lb = C.upper_bound({i + 1, 0});
    auto ok = C.end();
    for (auto it = C.begin(); it != lb; it++) {
      auto &[p, _] = *it;
      if (ok == C.end() || p.second > ok->first.second)
        ok = it;
    }

    if (ok != C.end()) {
      ans += ok->first.second;
      ok->second--;
      if (ok->second <= 0)
        C.erase(ok);
    }

    i++;
  }

  cout << ans << endl;
}
