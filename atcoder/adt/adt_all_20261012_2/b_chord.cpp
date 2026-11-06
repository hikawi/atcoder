#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string s;
  unordered_set<string> A = {"ACE", "BDF", "CEG", "DFA", "EGB", "FAC", "GBD"};
  cin >> s;
  if (A.contains(s))
    cout << "Yes\n";
  else
    cout << "No\n";

  return 0;
}
