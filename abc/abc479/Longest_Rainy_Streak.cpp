#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  string s;
  cin >> n >> s;

  int cont = 0;
  int maxcont = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'R') {
      cont++;
      maxcont = max(cont, maxcont);
    } else {
      cont = 0;
    }
  }

  cout << maxcont << "\n";

  return 0;
}
