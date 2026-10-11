#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> A(n);
  rep(i, n) cin >> A[i];

  int s = 0;
  for (int i = 0; i < n; i += 2)
    s += A[i];
  cout << s << "\n";

  return 0;
}
