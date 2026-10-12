#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<ll> A(n), B(n);
  rep(i, n) cin >> A[i];
  rep(i, n) cin >> B[i];

  cout << *max_element(A.begin(), A.end()) + *max_element(B.begin(), B.end()) << "\n";

  return 0;
}
