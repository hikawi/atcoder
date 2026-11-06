#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
ll mod = 1e9 + 7;

int main() {
  int n, q;
  string s;
  cin >> n >> q >> s;

  vector<ll> B(n + 1), H(n + 1);
  H[0] = 0;
  B[0] = 1;
  for (int i = 1; i <= n; i++) {
    B[i] = (B[i - 1] * 100) % mod;
    H[i] = ((H[i - 1] * 100) % mod + s[i - 1] - 'a' + 1) % mod;
  }

  auto hash = [&](int l, int r) {
    ll h = (H[r] - B[r - l + 1] * H[l - 1]) % mod;
    if (h < 0)
      h += mod;
    return h;
  };

  while (q--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (hash(a, b) == hash(c, d))
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}
