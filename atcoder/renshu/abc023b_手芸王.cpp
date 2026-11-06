#include <ios>
#include <iostream>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  string s;
  cin >> n >> s;

  if (n % 2 == 0) {
    cout << -1 << "\n";
    return 0;
  }

  int l = 0, r = n - 1;
  int a = 0;
  while (l < r) {
    if (s[l] == s[r] && s[l] == 'b') {
      a++;
      l++;
      r--;
    } else if (s[l] == 'c' && s[r] == 'a') {
      a++;
      l++;
      r--;
    } else if (s[l] == 'a' && s[r] == 'c') {
      a++;
      l++;
      r--;
    } else {
      cout << "-1\n";
      return 0;
    }
  }

  if (s[l] == 'b' && l >= r)
    cout << a << "\n";
  else
    cout << "-1\n";

  return 0;
}
