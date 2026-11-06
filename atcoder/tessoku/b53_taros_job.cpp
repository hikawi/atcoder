#include <iostream>
#include <queue>
using namespace std;

int main() {
  int n, d;
  cin >> n >> d;
  priority_queue<int> pq;
  vector<vector<int>> days(2001);

  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    days[x].push_back(y);
  }

  int c = 1;
  int ans = 0;
  while (c <= d) {
    pq.push_range(days[c]);
    if (!pq.empty()) {
      ans += pq.top();
      pq.pop();
    }
    c++;
  }
  cout << ans << endl;
}
