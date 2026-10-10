#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  cin >> n;
  vector<ll> A(n);
  rep(i, n) cin >> A[i];

  vector<ll> R(n), RR(n); // ranking -> index, index -> ranking
  {
    vector<pair<ll, ll>> ranks(n);
    rep(i, n) {
      ranks[i] = make_pair(i, A[i]);
    }
    sort(ranks.begin(), ranks.end(), [](const auto &a, const auto &b) { return a.second < b.second; });
    rep(i, n) {
      R[i] = ranks[i].first;
      RR[ranks[i].first] = i;
    }
  }

  ll med = (n - 1) / 2;
  rep(i, n) {
    ll r = RR[i];
    ll ri = med >= r ? med + 1 : med;
    cout << A[R[ri]] << "\n";
  }

  return 0;
}
