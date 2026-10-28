#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  unordered_set<string> S;
  unordered_set<char> lol = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};

  rep(i, n) {
    string s;
    cin >> s;

    if (s[0] != 'H' && s[0] != 'D' && s[0] != 'C' && s[0] != 'S') {
      cout << "No\n";
      return 0;
    }
    if (!lol.contains(s[1])) {
      cout << "No\n";
      return 0;
    }
    if (S.contains(s)) {
      cout << "No\n";
      return 0;
    }

    S.insert(s);
  }

  cout << "Yes\n";

  return 0;
}
