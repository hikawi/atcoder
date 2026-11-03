#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
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

int h, w;
int sx, sy;
int ex, ey;
vector<string> G;
vector<int> V;

void bfs() {
  queue<pii> q;
  V[sy * w + sx] = 0;
  q.emplace(sy * w + sx, 0);
  while (!q.empty()) {
    auto [id, cost] = q.front();
    q.pop();
    int x = id % w, y = id / w;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    rep(i, 0, 4) {
      int nx = x + dx[i], ny = y + dy[i], nid = ny * w + nx;
      if (nx < 0 || nx >= w || ny < 0 || ny >= h || V[nid] >= 0 || G[ny][nx] == '#')
        continue;
      V[nid] = cost + 1;
      q.emplace(nid, cost + 1);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << setprecision(13);
  cin >> h >> w >> sy >> sx >> ey >> ex;
  sx--;
  sy--;
  ex--;
  ey--;
  G = vector<string>(h);
  V = vector<int>(h * w, -1);
  rep(i, 0, h) cin >> G[i];

  bfs();
  cout << V[ey * w + ex] << el;
}
