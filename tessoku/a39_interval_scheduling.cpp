#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> M(n);
  for (int i = 0; i < n; i++)
    cin >> M[i].second >> M[i].first;
  sort(M.begin(), M.end());

  int ans = 0, last = 0;
  for (auto &p : M) {
    if (p.second >= last) {
      ans++;
      last = p.first;
    }
  }
  cout << ans << endl;
}
