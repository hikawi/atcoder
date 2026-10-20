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

  vector<int> dp(n + 1), parents(100001, -1);
  dp[1] = 0;
  dp[2] = A[2];
  parents[2] = 1;
  for (int i = 3; i <= n; i++) {
    int l = dp[i - 1] + A[i];
    int ll = dp[i - 2] + B[i];
    if (l < ll) {
      dp[i] = l;
      parents[i] = i - 1;
    } else {
      dp[i] = ll;
      parents[i] = i - 2;
    }
  }

  vector<int> path;
  int c = n;
  while (c > 0) {
    path.push_back(c);
    c = parents[c];
  }

  cout << path.size() << endl;
  for (auto it = path.rbegin(); it != path.rend(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}
