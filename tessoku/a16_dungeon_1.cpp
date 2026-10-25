#include <algorithm>
#include <iostream>
#include <vector>
int main() {
  using namespace std;

  int n;
  cin >> n;
  vector<int> A(n + 1), B(n + 1);
  for (int i = 2; i <= n; i++)
    cin >> A[i];
  for (int i = 3; i <= n; i++)
    cin >> B[i];

  vector<int> dp(n + 1);
  dp[1] = 0;
  dp[2] = A[2];
  for (int i = 3; i <= n; i++) {
    int a = dp[i - 2] + B[i];
    int b = dp[i - 1] + A[i];
    dp[i] = min(a, b);
  }

  cout << dp[n] << endl;
}
