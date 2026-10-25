#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
using pii = pair<int, int>;
int main() {
  int n;
  cin >> n;

  vector<pii> A(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> A[i].first >> A[i].second;
    A[i].second = -A[i].second;
  }
  sort(A.begin(), A.end());

  vector<int> B(n + 1);
  for (int i = 1; i <= n; i++)
    B[i] = -A[i].second;

  vector<int> dp(n + 1), L(n + 1);
  int len = 0;
  for (int i = 1; i <= n; i++) {
    int pos = lower_bound(L.begin() + 1, L.begin() + 1 + len, B[i]) - L.begin();
    dp[i] = pos;
    L[dp[i]] = B[i];
    if (dp[i] > len)
      len++;
  }

  cout << len << endl;
}
