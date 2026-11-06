#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  unordered_set<string> S;
  S.insert("ABC");
  S.insert("AGC");
  S.insert("ARC");
  S.insert("AHC");

  rep(i, 3) {
    string s;
    cin >> s;
    S.erase(s);
  }

  cout << *S.begin() << endl;

  return 0;
}
