#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  int n, x, y;
  cin >> n >> x >> y;
  vector<ll> A(n);
  for (int i = 0; i < n; i++)
    cin >> A[i];

  // 0 0 1 1 2
  // dp[5]からループ
  auto grundy = [&](ll n) {
    int a[] = {0, 0, 1, 1, 2};
    return a[n % 5];
  };

  ll a = grundy(A[0]);
  for (int i = 1; i < n; i++)
    a ^= grundy(A[i]);

  if (a)
    cout << "First\n";
  else
    cout << "Second\n";
}
