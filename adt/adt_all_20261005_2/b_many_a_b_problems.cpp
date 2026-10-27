#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  rep(i, n) {
    ll a, b;
    cin >> a >> b;
    cout << a + b << endl;
  }
  return 0;
}
