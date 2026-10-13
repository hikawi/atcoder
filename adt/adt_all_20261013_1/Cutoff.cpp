#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, x;
  cin >> n >> x;
  vector<int> A(n - 1);
  rep(i, n - 1) cin >> A[i];
  sort(A.begin(), A.end());

  int s = 0;
  for (const auto a : A)
    s += a;

  for (int i = 0; i <= 100; i++) {
    auto it = lower_bound(A.begin(), A.end(), i);

    if (it == A.begin()) {
      // if at start
      if (s - A.back() >= x) {
        cout << i << "\n";
        return 0;
      }
    } else if (it == A.end()) {
      // if at end
      if (s - A.front() >= x) {
        cout << i << "\n";
        return 0;
      }
    } else {
      // at mid
      int total = s - A.front() - A.back() + i;
      if (total >= x) {
        cout << i << "\n";
        return 0;
      }
    }
  }
  cout << -1 << "\n";

  return 0;
}
