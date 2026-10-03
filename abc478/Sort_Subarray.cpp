#include <bits/stdc++.h>
#include <ranges>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int pre{}, left{};
  for (const auto &[i, v] : a | views::enumerate) {
    pre = max(pre, v);
    if (pre > v)
      left = i;
  }

  int suf{n}, right{n};
  for (const auto &[i, v] : a | views::enumerate | views::reverse) {
    suf = min(suf, v);
    if (suf < v)
      right = i;
  }

  if (k + right > left)
    cout << "Yes";
  else
    cout << "No";
}
