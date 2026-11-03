#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
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
using i128 = __int128;

template <typename T> using uset = unordered_set<T>;
template <typename K, typename V> using umap = unordered_map<K, V>;
template <typename T, int N> using arr = array<T, N>;

#define rep(i, x, limit)   for (ll i = ll(x); i < ll(limit); i++)
#define repeq(i, x, limit) for (ll i = ll(x); i <= ll(limit); i++)
#define all(x)             x.begin(), x.end()
#define rall(x)            x.rbegin(), x.rend()
#define el                 '\n'
#define spa                ' '
#define Yes                cout << "Yes" << el
#define No                 cout << "No" << el
#define YES                cout << "YES" << el
#define NO                 cout << "NO" << el
#define MAYBE              cout << "MAYBE" << el
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
ll modpow(ll a, ll b, ll m) {if (b == 0)return 1;ll c = 1, d = a;while (b) {if (b & 1)c = (c * d) % m;d = (d * d) % m;b >>= 1;}return c;}
ll moddiv(ll a, ll b, ll m) {return (a * modpow(b, m - 2, m)) % m;}
// clang-format on

vector<int> parents;

int root(int v) {
  if (parents[v] == v)
    return v;
  parents[v] = root(parents[v]);
  return parents[v];
}

bool same(int u, int v) {
  return root(u) == root(v);
}

void merge(int u, int v) {
  parents[root(u)] = root(v);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << setprecision(13);
  int n, m;
  cin >> n >> m;
  vector<pii> edges(m);
  rep(i, 0, m) {
    int u, v;
    cin >> u >> v;
    edges[i] = {u - 1, v - 1};
  }

  parents = vector<int>(n);
  vector<int> removed(m);
  iota(all(parents), 0);

  int q;
  cin >> q;
  vector<pii> queries(q);
  rep(i, 0, q) {
    int t;
    cin >> t;
    if (t == 1) {
      int n;
      cin >> n;
      queries[i] = {n - 1, -1};
    } else {
      int u, v;
      cin >> u >> v;
      queries[i] = {u - 1, v - 1};
    }
  }

  for (auto &[u, v] : queries) {
    if (v != -1)
      continue;
    removed[u] = 1;
  }

  // the after state
  rep(i, 0, m) {
    if (removed[i])
      continue;
    auto [u, v] = edges[i];
    merge(u, v);
  }

  vector<int> ans;
  for (auto &[u, v] : queries | views::reverse) {
    if (v == -1) {
      merge(edges[u].first, edges[u].second);
    } else {
      ans.push_back(same(u, v));
    }
  }

  for (auto i : ans | views::reverse)
    if (i)
      Yes;
    else
      No;
}
