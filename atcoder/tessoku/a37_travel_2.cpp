#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  ll n, m, b;
  cin >> n >> m >> b;
  vector<ll> A(n), C(m);
  for (int i = 0; i < n; i++)
    cin >> A[i];
  for (int i = 0; i < m; i++)
    cin >> C[i];

  ll ans = 0;
  ans += b * n * m;
  for (auto a : A)
    ans += a * m;
  for (auto c : C)
    ans += c * n;
  cout << ans << endl;
}
