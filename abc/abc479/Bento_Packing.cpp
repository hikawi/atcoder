#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  ll w;
  cin >> n >> w;
  vector<ll> A(n), B(n);
  rep(i, n) {
    cin >> A[i] >> B[i];
  }

  ll happy = 0;
  for (int i = 0; i < (1 << n); i++) {
    ll curhappy = 0, curweight = 0;
    int a = i;
    for (int j = 0; j < n; j++) {
      if (a % 2) {
        curhappy += A[j];
        curweight += B[j];
      }
      a /= 2;
    }

    if (curweight <= w)
      happy = max(happy, curhappy);
  }

  cout << happy << "\n";

  return 0;
}
