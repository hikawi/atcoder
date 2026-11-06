#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  auto it = remove_if(s.begin(), s.end(), [](const auto c) { return c == '.'; });
  s.erase(it, s.end());
  cout << s << endl;

  return 0;
}
