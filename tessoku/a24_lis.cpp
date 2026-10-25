#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> A(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> A[i];

  vector<int> dp(n + 1), L(n + 1);
  int len = 0;
  for (int i = 1; i <= n; i++) {
    int pos = lower_bound(L.begin() + 1, L.begin() + 1 + len, A[i]) - L.begin();
    dp[i] = pos;
    L[dp[i]] = A[i];
    if (dp[i] > len)
      len++;
  }

  cout << len << endl;
}
