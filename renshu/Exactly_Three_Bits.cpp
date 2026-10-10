#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  // generate all numbers that have popcount 3
  vector<ull> nums;
  {
    array<bool, 64> mask{};
    mask[63] = 1;
    mask[62] = 1;
    mask[61] = 1;

    do {
      // compute the no
      ull a = 0;
      rep(i, 64) if (mask[i]) a |= (1ull << i);
      nums.push_back(a);
    } while (next_permutation(mask.begin(), mask.end()));
  }
  sort(nums.begin(), nums.end());

  ull t;
  cin >> t;
  rep(ti, t) {
    ull n;
    cin >> n;
    auto it = lower_bound(nums.begin(), nums.end(), n);
    if (it == nums.end()) {
      cout << nums.back() << "\n";
    } else if (*it == n) {
      cout << n << "\n";
    } else if (it == nums.begin()) {
      cout << -1 << "\n";
    } else {
      cout << *(it - 1) << "\n";
    }
  }

  return 0;
}
