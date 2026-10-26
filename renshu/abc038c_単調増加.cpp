#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll nCr(ll n, ll r) {
  if (n < r)
    return 0;
  double sum = 1;
  for (int i = 1; i <= r; i++)
    sum = sum * (n - r + i) / i;
  return (ll)sum;
}

int main() {
  int n;
  cin >> n;
  vector<ll> A(n + 1);
  for (int i = 0; i < n; i++)
    cin >> A[i];
  A[n] = -(1ll << 60);

  ll l = 0, r = 1, c = n;
  while (l < n && r < n) {
    while (r < n && A[r] > A[r - 1])
      r++;

    // cout << l << "," << r << endl;
    c += nCr(r - l, 2);
    l = r;
    r++;
  }

  cout << c << endl;
}
