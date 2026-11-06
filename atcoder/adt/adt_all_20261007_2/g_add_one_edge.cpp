#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll n1, n2, q;
  cin >> n1 >> n2 >> q;

  vector<vector<int>> adj(n1 + n2);
  rep(i, q) {
    ll a, b;
    cin >> a >> b;
    adj[a - 1].push_back(b - 1);
    adj[b - 1].push_back(a - 1);
  }

  // if i < n1, then its dist to node 0
  // if i >= n1, then its dist to node n1+n2-1
  vector<ll> dist(n1 + n2, LONG_LONG_MAX);
  dist[0] = 0;
  dist[n1 + n2 - 1] = 0;

  // one dijkstra to find all
  {
    queue<pair<int, ll>> q;
    q.emplace(0, 0);
    q.emplace(n1 + n2 - 1, 0);

    while (!q.empty()) {
      auto [cur, cost] = q.front();
      q.pop();
      for (auto neighbor : adj[cur]) {
        ll alt = cost + 1;
        if (alt < dist[neighbor]) {
          dist[neighbor] = alt;
          q.emplace(neighbor, alt);
        }
      }
    }
  }

  // for (const auto l : dist)
  //   cout << l << " ";
  // cout << endl;

  cout << *max_element(dist.begin(), dist.begin() + n1) + *max_element(dist.begin() + n1, dist.end()) + 1 << endl;
  return 0;
}
