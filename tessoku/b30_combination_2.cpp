#include <iostream>
using namespace std;
using ll = long long;
ll m = 1000000007;
ll power(ll a, ll b) {
  if (b == 0)
    return 1;
  if (b == 1)
    return a;
  ll ans = a;
  ll cur = 1;
  while (cur + cur < b) {
    cur += cur;
    ans = (ans * ans) % m;
  }
  return (ans * power(a, max(0ll, b - cur))) % m;
}
ll nCr(ll n, ll r) {
  ll nom = 1, denom = 1;
  for (int i = 2; i <= n; i++)
    nom = (nom * i) % m;
  for (int i = 1; i <= r; i++)
    denom = (denom * i) % m;
  for (int i = 1; i <= n - r; i++)
    denom = (denom * i) % m;
  return (nom * power(denom, m - 2)) % m;
}
int main() {
  int h, w;
  cin >> h >> w;
  cout << nCr(h + w - 2, w - 1) << endl;
}
