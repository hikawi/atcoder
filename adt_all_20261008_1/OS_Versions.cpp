#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  unordered_map<string, int> vers = {};
  vers["Ocelot"] = 0;
  vers["Serval"] = 1;
  vers["Lynx"] = 2;

  string a, b;
  cin >> a >> b;

  cout << ((vers[a] >= vers[b]) ? "Yes\n" : "No\n");

  return 0;
}
