#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> A(n);
  int m = 0;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    m = max(m, A[i]);
  }

  vector<int> dp(m + 1);
  for (int i = 0; i <= m; i++) {
    array<int, 3> A{};
    if (i - x >= 0)
      A[dp[i - x]]++;
    if (i - y >= 0)
      A[dp[i - y]]++;
    for (int j = 0; j < 3; j++) {
      if (!A[j]) {
        dp[i] = j;
        break;
      }
    }
  }

  int v = dp[A[0]];
  for (int i = 1; i < n; i++)
    v ^= dp[A[i]];

  if (v)
    cout << "First\n";
  else
    cout << "Second\n";
}
