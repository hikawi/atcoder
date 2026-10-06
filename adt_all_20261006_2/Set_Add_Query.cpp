#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, q;
  cin >> n >> q;

  vector<ll> A(n);
  unordered_set<ll> S;
  ll sum = 0;

  rep(qi, q) {
    int x;
    cin >> x;
    x--;

    if (S.find(x) == S.end()) {
      // inserting
      A[x] -= sum;
      S.insert(x);
    } else {
      A[x] += sum;
      S.erase(x);
    }
    sum += S.size();
  }

  for (const auto l : S)
    A[l] += sum;

  for (const auto l : A)
    cout << l << " ";
  cout << endl;

  return 0;
}
