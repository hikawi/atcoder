#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  stack<pair<int, int>> s;
  int n;
  cin >> n;

  rep(i, n) {
    int a;
    cin >> a;

    if (s.empty() || s.top().first != a) {
      s.emplace(a, 1);
      continue;
    } else if (s.top().second < 3) {
      s.top().second++;
    } else {
      s.pop();
    }
  }

  int c = 0;
  while (!s.empty()) {
    auto a = s.top();
    s.pop();
    c += a.second;
  }
  cout << c << "\n";

  return 0;
}
