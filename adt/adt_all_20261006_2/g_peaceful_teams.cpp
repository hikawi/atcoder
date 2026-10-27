#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)

unordered_map<int, ll> cache;

ll fact(int n) {
  ll prod = 1;
  for (int i = 1; i <= n; i++)
    prod *= i;
  return prod;
}

ll stirling(int n, int k) {
  if (k > n || k == 0) {
    return 0;
  }
  if (k == 1) {
    return 1;
  }
  if (n == k) {
    return 1;
  }

  int idx = (n - 1) * 10 + (k - 1);
  if (cache.find(idx) != cache.end()) {
    return cache[idx];
  }

  ll res = 0;
  if (k == 2) {
    res = pow(2, n - 1) - 1;
  } else if (n == k + 1) {
    // n choose 2 = n! / (k! (n-k)!)
    res = fact(n) / (fact(k) * fact(n - k));
  } else {
    res = stirling(n - 1, k - 1) + k * stirling(n, k - 1);
  }

  cache[idx] = res;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, t, m;
  cin >> n >> t >> m;
  unordered_map<int, unordered_set<int>> incomp;
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    incomp[a].insert(b);
    incomp[b].insert(a);
  }

  vector<int> order(n);
  cout << stirling(n, t) << endl;

  return 0;
}
