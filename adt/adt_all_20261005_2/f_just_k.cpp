#include <algorithm>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  vector<string> S(n);
  rep(i, n) cin >> S[i];

  ll ans = 0;
  for (int i = 1; i < 1 << n; i++) {
    array<int, 26> C{};
    int j = 0, cur = i;
    while (cur) {
      if (cur % 2)
        for (auto c : S[j])
          C[c - 'a']++;
      cur >>= 1;
      j++;
    }

    ll curans = 0;
    for (auto a : C)
      if (a == k)
        curans++;
    ans = max(ans, curans);
  }
  cout << ans << endl;

  return 0;
}
