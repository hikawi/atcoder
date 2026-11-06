// Problem: $name
// URL: $url
// Group: $group

#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <map>
#include <ranges>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template <typename T> using uset = unordered_set<T>;
template <typename K, typename V> using umap = unordered_map<K, V>;
template <typename T, int N> using arr = array<T, N>;

#define rep(i, x, limit)   for (ll i = (ll)x; i < (ll)limit; i++)
#define repeq(i, x, limit) for (ll i = (ll)x; i <= (ll)limit; i++)
#define all(x)             x.begin(), x.end()
#define rall(x)            x.rbegin(), x.rend()
#define el                 '\n'
#define spa                ' '
#define Yes                cout << "Yes" << el
#define No                 cout << "No" << el
#define YES                cout << "YES" << el
#define NO                 cout << "NO" << el
#define eps                (1e-10)
#define Equals(a, b)       (fabs((a) - (b)) < eps)
#define debug(x)           cerr << #x << "=" << x << el

const int inf = 1073741823;
const ll infl = 1LL << 60;
const string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string abc = "abcdefghijklmnopqrstuvwxyz";

// clang-format off
template <typename T1, typename T2> std::ostream &operator<<(std::ostream &os, std::pair<T1, T2> p) {os << "(" << p.first << "," << p.second << ")";return os;}
template <typename T> inline void print_vec(const vector<T> &v, bool split_line = false) {if (v.empty()) {cout << "[]" << el;return;}constexpr bool isValue = is_integral<T>::value;for (int i = 0; i < (int)v.size(); i++) {if constexpr (isValue) {if ((v[i] == inf) || (v[i] == infl)) cout << 'x' << ",\n"[split_line || i + 1 == (int)v.size()]; else cout << v[i] << ",\n"[split_line || i + 1 == (int)v.size()];} else cout << v[i] << ",\n"[split_line || i + 1 == (int)v.size()];}}
template <typename T1, typename T2> inline void print_vec(const vector<pair<T1, T2>> &v, bool split_line = false) {if (v.empty()) {cout << "[]" << el;return;}for (int i = 0; i < (int)v.size(); i++) {cout << '(';auto [a, b] = v[i];constexpr pair<bool, bool> isValue = {is_integral<T1>::value, is_integral<T2>::value};if constexpr (isValue.first) {if (a == inf || a == infl)cout << "x,";else cout << a << ",";} else cout << a << ","; if constexpr (isValue.second) { if (b == inf || b == infl) cout << "x,";else cout << b;} else cout << b;cout << ")" << " \n"[split_line || i + 1 == (int)v.size()];}}
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) {bool compare = a < b;if (compare)a = b;return compare;}
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) {bool compare = a > b;if (compare)a = b;return compare;}
// clang-format on

int n;
vector<vector<int>> adj;
vector<vector<int>> C;

vector<int> depth;
vector<vector<int>> up;

void dfs(int v, int p, int d) {
  depth[v] = d;
  up[v][0] = p;

  // 2^20 dude why do i not know binary lifting
  rep(i, 1, 20) up[v][i] = up[up[v][i - 1]][i - 1]; // black magic

  for (auto n : adj[v])
    if (n != p)
      dfs(n, v, d + 1);
}

// geeksforgeeks black magic
int lca(int u, int v) {
  if (depth[u] < depth[v])
    swap(u, v);

  for (int i = 19; i >= 0; i--)
    if (depth[u] - (1 << i) >= depth[v])
      u = up[u][i];

  if (u == v)
    return u;

  for (int i = 19; i >= 0; i--)
    if (up[u][i] != up[v][i]) {
      u = up[u][i];
      v = up[v][i];
    }

  return up[u][0];
}

int maxd = 0;
int maxi = 0;
vector<int> V;

void idk(int v, int d) {
  if (V[v])
    return;

  if (d > maxd) {
    maxd = d;
    maxi = v;
  }

  V[v] = 1;
  for (auto n : adj[v])
    if (!V[n])
      idk(n, d + 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << setprecision(13);

  cin >> n;
  adj = vector<vector<int>>(n);
  C = vector<vector<int>>(n);
  depth.resize(n);
  up.resize(n, vector<int>(20, 0));

  rep(i, 0, n - 1) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  rep(i, 0, n) {
    int c;
    cin >> c;
    C[c - 1].push_back(i);
  }

  dfs(0, 0, 0);

  V.resize(n, 0);
  idk(0, 0);
  V.assign(n, 0);
  maxd = 0;
  idk(maxi, 0);

  int dia = maxd;
  ll ans = 0;
  for (auto &c : C) {
    if (c.size() < 2)
      continue;

    rep(i, 0, c.size()) {
      rep(j, i + 1, c.size()) {
        int u = c[i];
        int v = c[j];
        int dist = depth[u] + depth[v] - 2 * depth[lca(u, v)];
        ans += dist == dia;
      }
    }
  }
  cout << ans << el;
}
