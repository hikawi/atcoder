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

  if (n % 2 == 0 || s[n / 2] != '/') {
    cout << "No\n";
    return 0;
  }
  for (int i = 0; i < n / 2; i++)
    if (s[i] != '1') {
      cout << "No\n";
      return 0;
    }
  for (int i = n / 2 + 1; i < n; i++)
    if (s[i] != '2') {
      cout << "No\n";
      return 0;
    }

  cout << "Yes\n";
  return 0;
}
