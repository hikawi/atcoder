#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> A(n);
  int m = 1;
  rep(i, n) {
    cin >> A[i];
    m = max(m, A[i]);
  }

  vector<int> sum(m);
  for (int a : A) {
    sum[a - 1]++;
  }
  partial_sum(sum.rbegin(), sum.rend(), sum.rbegin());

  int i = 0, carry = 0;
  while (i < sum.size()) {
    sum[i] += carry;
    carry = 0;
    if (sum[i] >= 10) {
      carry = sum[i] / 10;
      sum[i] %= 10;
    }
    if (i == sum.size() - 1 && carry > 0) {
      sum.push_back(carry);
      carry = 0;
    }
    i++;
  }

  for (const auto s : sum | views::reverse)
    cout << s;
  cout << "\n";

  return 0;
}
