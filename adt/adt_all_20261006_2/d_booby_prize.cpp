#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<pair<int, ll>> A(n);
  rep(i, n) {
    ll a;
    cin >> a;
    A[i] = pair(i + 1, a);
  }

  sort(A.begin(), A.end(), [](const auto a, const auto b) { return a.second < b.second; });
  cout << A[n - 2].first << endl;

  return 0;
}
