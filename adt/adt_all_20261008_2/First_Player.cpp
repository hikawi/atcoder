#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<pair<int, string>> ppl;
  rep(i, n) {
    string name;
    int age;
    cin >> name >> age;
    ppl.emplace_back(age, name);
  }

  auto it = min_element(ppl.begin(), ppl.end());
  for (auto i = it; i != ppl.end(); i++)
    cout << i->second << "\n";
  for (auto i = ppl.begin(); i < it; i++)
    cout << i->second << "\n";

  return 0;
}
