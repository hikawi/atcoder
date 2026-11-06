#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
ll mod = 1000000007;
ll power(ll a, ll b) {
  if (b == 0)
    return 1;
  if (b == 1)
    return a;

  ll ans = a;
  ll cur = 1;
  while (cur + cur < b) {
    cur += cur;
    ans = (ans * ans) % mod;
  }

  return (ans * power(a, max(0ll, b - cur))) % mod;
}
int main() {
  ll a, b;
  cin >> a >> b;
  cout << power(a, b) << endl;
}
