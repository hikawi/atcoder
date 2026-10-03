#include <bits/stdc++.h>
using namespace std;

struct Range {
  vector<pair<int, int>> ranges;

  bool can_merge(pair<int, int> a, pair<int, int> b) {
    return max(a.first, b.first) <= min(a.second, b.second) + 1;
  }

  void add(pair<int, int> p) {
    pair<int, int> cur = p;
    bool found = true;
    while (found) {
      found = false;
      for (auto it = ranges.begin(); it != ranges.end(); it++) {
        if (can_merge(cur, *it)) {
          found = true;
          cur = pair(min(cur.first, it->first), max(cur.second, it->second));
          ranges.erase(it);
          break;
        }
      }
    }

    ranges.push_back(cur);
  }

  bool has(int i) const {
    for (const auto &p : ranges) {
      if (p.first <= i && p.second >= i)
        return true;
    }
    return false;
  }

  void print() const {
    for (const auto &pair : ranges) {
      cout << " (" << pair.first << "," << pair.second << ")";
    }
    cout << endl;
  }
};

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  unordered_map<int, Range> nums;
  for (int i = 0; i < q; i++) {
    int l, r, x;
    cin >> l >> r >> x;
    nums[x].add(pair(l, r));
  }

  for (int i = 0; i < n; i++) {
    for (const auto &[_, v] : nums) {
      if (v.has(i + 1)) {
        a[i]++;
      }
    }
    if (i != 0)
      cout << " ";
    cout << a[i];
  }
}