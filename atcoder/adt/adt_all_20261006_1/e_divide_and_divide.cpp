#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)

ll cost(ll no, unordered_map<ll, ll> &cache) {
  if (no <= 1) {
    return 0;
  }
  if (no == 2) {
    return 2;
  }
  if (cache.find(no) != cache.end()) {
    return cache[no];
  }

  ll c = no + cost(no / 2, cache) + cost(no / 2 + no % 2, cache);
  cache[no] = c;
  return c;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  cin >> n;

  unordered_map<ll, ll> cache;
  cout << cost(n, cache) << endl;

  return 0;
}
