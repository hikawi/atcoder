#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<int> A(m), B(m);

  rep(i, n) {
    int a, b;
    cin >> a >> b;
    A[a - 1]++;
    B[b - 1]++;
  }

  rep(i, m) {
    cout << B[i] - A[i] << "\n";
  }

  return 0;
}
