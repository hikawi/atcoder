#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int main() {
  int n, l;
  cin >> n >> l;
  vector<pair<int, char>> A(n);
  for (int i = 0; i < n; i++)
    cin >> A[i].first >> A[i].second;

  int ans = 0;
  for (auto &p : A) {
    if (p.second == 'E')
      ans = max(ans, l - p.first);
    else
      ans = max(ans, p.first);
  }
  cout << ans << endl;
}
