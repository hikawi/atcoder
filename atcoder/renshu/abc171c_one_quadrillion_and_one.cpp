#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

string parse(ll n) {
  if (n == 0)
    return "a";

  string s;
  while (n) {
    n--;
    ll c = n % 26;
    s.push_back(char('a' + c));
    n /= 26;
  }
  reverse(s.begin(), s.end());
  return s;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  unsigned long long n;
  cin >> n;

  cout << parse(n) << "\n";

  return 0;
}
