#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int ratecolor(ll rate) {
  if (rate >= 3200)
    return -1;
  return rate / 400;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  unordered_set<int> A;
  ll wild = 0;
  ll n;
  cin >> n;
  rep(i, n) {
    ll rate;
    cin >> rate;

    int col = ratecolor(rate);
    if (col == -1)
      wild++;
    else
      A.insert(col);
  }

  cout << max(A.size(), 1ul) << " ";
  cout << A.size() + wild << "\n";

  return 0;
}
