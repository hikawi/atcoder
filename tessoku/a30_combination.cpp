#include <iostream>
#include <vector>
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
int main() {
  ll n, r;
  cin >> n >> r;

  vector<ll> fact(100001);
  ll p = 1;
  fact[0] = 1;
  fact[1] = p;
  for (int i = 2; i <= 100000; i++) {
    p = (p * i) % m;
    fact[i] = p;
  }

  ll nom = fact[n] % m;
  ll denom = (fact[r] * (fact[n - r])) % m;
  cout << (nom * power(denom, m - 2)) % m << endl;
}
