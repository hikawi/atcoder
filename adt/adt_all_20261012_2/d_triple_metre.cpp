#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string t;
  for (int i = 0; i < 10; i++)
    t += "oxx";
  string s;
  cin >> s;
  if (t.contains(s))
    cout << "Yes\n";
  else
    cout << "No\n";

  return 0;
}
