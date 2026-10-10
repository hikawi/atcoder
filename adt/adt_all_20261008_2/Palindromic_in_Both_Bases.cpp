#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll a, n;
  cin >> a >> n;

  int bits = ceil(log(n) / log(a));
  rep(count, bits) {
    vector<int> digits(count + 1);
  }

  return 0;
}
