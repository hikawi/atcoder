#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

vector<ll> A;
vector<vector<ll>> E;

vector<bool> ans;
vector<bool> V;
int cnt = 0;
unordered_map<ll, int> S;

template <typename It> void printit(It &i) {
  for (auto it = i.begin(); it != i.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

void dfs(ll cur) {
  V[cur] = true;
  S[A[cur]]++;
  if (S[A[cur]] > 1)
    cnt++;
  if (cnt > 0)
    ans[cur] = true;

  for (const auto next : E[cur]) {
    if (!V[next])
      dfs(next);
  }
  S[A[cur]]--;
  if (S[A[cur]])
    cnt--;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  cin >> n;

  A = vector<ll>(n);
  E = vector<vector<ll>>(n);
  V = vector<bool>(n);
  ans = vector<bool>(n);
  rep(i, n) {
    ll a;
    cin >> a;
    A[i] = a;
  }
  rep(i, n - 1) {
    int u, v;
    cin >> u >> v;
    E[u - 1].push_back(v - 1);
    E[v - 1].push_back(u - 1);
  }

  dfs(0);
  for (const auto b : ans)
    cout << (b ? "Yes\n" : "No\n");

  return 0;
}
