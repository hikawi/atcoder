#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  int n;
  cin >> n;
  vector<ll> A(101);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    A[a]++;
  }

  auto tris = [&](ll n) { return (n * (n - 1) * (n - 2)) / 6; };

  ll ans = 0;
  for (int i = 0; i <= 100; i++)
    ans += tris(A[i]);
  cout << ans << endl;
}
