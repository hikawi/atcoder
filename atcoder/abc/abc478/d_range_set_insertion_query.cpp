#include <algorithm>
#include <deque>
#include <iostream>
#include <unordered_map>
#include <utility>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  deque<pair<int, int>> E;
  unordered_map<int, int> S;

  for (int qi = 0; qi < q; qi++) {
    int l, r, x;
    cin >> l >> r >> x;
    E.emplace_back(l, x);
    E.emplace_back(r + 1, -x);
  }
  sort(E.begin(), E.end());

  int t = 1;
  while (t <= n) {
    while (!E.empty() && E.front().first == t) {
      int v = E.front().second < 0 ? -E.front().second : E.front().second;
      if (E.front().second < 0)
        S[v]--;
      else
        S[v]++;
      if (S[v] <= 0)
        S.erase(v);
      E.pop_front();
    }

    cout << S.size() << " ";
    t++;
  }
  cout << endl;
}
