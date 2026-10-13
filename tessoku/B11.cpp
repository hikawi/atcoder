#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

#define rep(i, x, limit) for (ll i = (ll)x; i < (ll)limit; i++)
#define all(x)           x.begin(), x.end()

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << setprecision(13);

  ll n;
  cin >> n;
  vector<ll> A(n);
  rep(i, 0, n) cin >> A[i];
  sort(all(A));

  ll q;
  cin >> q;
  rep(qi, 0, q) {
    ll a;
    cin >> a;
    auto i = lower_bound(all(A), a) - A.begin();
    cout << i << "\n";
  }
}
