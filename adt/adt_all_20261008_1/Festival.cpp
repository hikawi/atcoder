#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<bool> A(n);
  rep(i, m) {
    int a;
    cin >> a;
    A[a - 1] = true;
  }

  vector<int> comp;
  int last;
  for (int i = n - 1; i >= 0; i--) {
    if (A[i]) {
      comp.push_back(0);
      last = i;
    } else {
      comp.push_back(i - last);
    }
  }

  for (const auto l : comp | views::reverse)
    cout << -l << "\n";

  return 0;
}
