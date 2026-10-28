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

  int c = 0;
  for (int i = 0; i < n - 2; i++) {
    if (A[i] < A[i + 1] && A[i + 1] > A[i + 2])
      c++;
  }
  cout << c << "\n";

  return 0;
}
