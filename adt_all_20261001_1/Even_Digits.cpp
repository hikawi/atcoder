#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  cin >> n;
  n--;

  string s;
  while (n) {
    s.push_back('0' + (n % 5));
    n /= 5;
  }

  if (s.empty()) {
    s = "0";
  }
  for (auto c : s | views::reverse) {
    cout << (c - '0') * 2;
  }
  cout << endl;

  return 0;
}
