#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
ll mod = 1e9 + 7;
int main() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;

  vector<ll> T(n + 1);
  for (int i = 1; i <= n; i++)
    T[i] = s[i - 1] - 'a' + 1;

  vector<ll> B(n + 1);
  vector<ll> HL(n + 1), HR(n + 1);
  B[0] = 1;
  HL[0] = 0;
  HR[0] = 0;
  for (int i = 1; i <= n; i++) {
    B[i] = (B[i - 1] * 100) % mod;
    HL[i] = ((HL[i - 1] * 100) + T[i]) % mod;
    HR[i] = ((HR[i - 1] * 100) + T[n - i + 1]) % mod;
  }

  auto hash = [&](int l, int r, int rev = 0) {
    ll ans;
    if (rev) {
      int nl = n - r + 1;
      int nr = n - l + 1;
      ans = (HR[nr] - B[nr - nl + 1] * HR[nl - 1] % mod) % mod;
    } else {
      ans = (HL[r] - B[r - l + 1] * HL[l - 1]) % mod;
    }
    if (ans < 0)
      ans += mod;
    return ans;
  };

  while (q--) {
    int l, r;
    cin >> l >> r;

    ll h1 = hash(l, r);
    ll h2 = hash(l, r, 1);
    if (h1 == h2)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}
