#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  int e = 0, w = 0;
  for (const char c : s)
    if (c == 'E')
      e++;
    else
      w++;

  if (e > w)
    cout << "East\n";
  else
    cout << "West\n";

  return 0;
}
