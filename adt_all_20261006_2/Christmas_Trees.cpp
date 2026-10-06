#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)

ll euclidmod(ll a, ll b) {
  ll r = a % b;
  if (r < 0)
    r += b;
  return r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll a, m, l, r;
  cin >> a >> m >> l >> r;

  r -= a;
  l -= a;

  ll rl = ((l - 1) % m + m) % m;
  ll rr = (r % m + m) % m;

  // counts of trees from 0 -> R - 0 -> L
  // ig thats a way to dodge LL limits?
  cout << ((r - rr) / m) - ((l - 1 - rl) / m) << endl;

  // but why is my original wrong
  // using euclid mod
  // in = (r - l) // m
  // left = (l % m) == (a % m)
  // right = (r % m) == (a % m)
  //
  // ans = in + (l == r ? left : left+right)?
  // seems to be off by 1 in some cases?

  return 0;
}
