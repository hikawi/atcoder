#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> A(n);
  vector<tuple<int, int>> Q;
  unordered_set<int> S;

  for (int qi = 0; qi < q; qi++) {
    int l, r, x;
    cin >> l >> r >> x;
    if (S.find(x) == S.end()) {
      S.insert(x);
      Q.emplace_back(l, 1);
      Q.emplace_back(r, -1);
    }
  }
}
