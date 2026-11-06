#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> A(k);
  for (int i = 0; i < k; i++)
    cin >> A[i];

  vector<int> dp(n + 1);
  for (int i = 0; i <= n; i++) {
    int cur = -1;
    for (auto a : A)
      if (i - a >= 0 && dp[i - a] == -1)
        cur = 1;
    dp[i] = cur;
  }

  cout << (dp[n] < 0 ? "Second" : "First") << endl;
}
