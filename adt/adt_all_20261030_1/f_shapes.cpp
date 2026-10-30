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

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << setprecision(13);
  int n;
  cin >> n;
  vector<string> S(n), T(n);
  rep(i, 0, n) cin >> S[i];
  rep(i, 0, n) cin >> T[i];

  bool f = 0;

  auto rotate = [&]() {
    vector<string> T(n, string(n, ' '));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        T[i][j] = S[j][i];
    for (auto &s : T)
      reverse(all(s));
    S.swap(T);
  };

  auto consolidate = [&](vector<string> &V) {
    int tx = n, ty = n;
    for (int y = 0; y < n; y++)
      for (int x = 0; x < n; x++)
        if (V[y][x] == '#') {
          chmin(tx, x);
          chmin(ty, y);
        }

    vector<pair<int, int>> S;
    for (int y = 0; y < n; y++)
      for (int x = 0; x < n; x++)
        if (V[y][x] == '#') {
          int dx = x - tx, dy = y - ty;
          S.emplace_back(dx, dy);
        }
    sort(all(S));
    return S;
  };

  auto ct = consolidate(T);

  auto check = [&]() {
    // consolidate S into a centroid center
    auto cs = consolidate(S);
    if (cs.size() != ct.size())
      return false;
    for (int i = 0; i < cs.size(); i++) {
      if (cs[i] != ct[i])
        return false;
    }
    return true;
  };

  for (int i = 0; i < 4; i++) {
    if (check()) {
      f = 1;
      break;
    }
    rotate();
  }

  if (f)
    Yes;
  else
    No;
}
