#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  rep(i, n) cin >> A[i];

  vector<int> R(n);
  copy(A.end() - k, A.end(), R.begin());
  copy(A.begin(), A.end() - k, R.begin() + k);

  for (const auto i : R)
    cout << i << " ";
  cout << endl;

  return 0;
}
