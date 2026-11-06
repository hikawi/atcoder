#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(3 * n);
  unordered_map<int, vector<int>> map;
  for (int i = 0; i < 3 * n; i++) {
    cin >> a[i];
    map[a[i]].push_back(i + 1);
  }

  vector<pair<int, int>> ans;
  for (int i = 1; i <= n; i++) {
    ans.push_back(pair(i, map[i][1]));
  }

  sort(ans.begin(), ans.end(), [&](pair<int, int> a, pair<int, int> b) -> bool { return b.second > a.second; });

  for (int i = 0; i < n; i++) {
    cout << ans[i].first;
    if (i != n - 1)
      cout << " ";
  }
  cout << endl;
}
