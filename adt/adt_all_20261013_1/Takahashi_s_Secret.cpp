#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, x;
  cin >> n >> x;
  vector<int> A(n);
  rep(i, n) cin >> A[i];

  unordered_set<int> S;
  while (!S.contains(x)) {
    S.insert(x);
    x = A[x - 1];
  }

  cout << S.size() << "\n";

  return 0;
}
