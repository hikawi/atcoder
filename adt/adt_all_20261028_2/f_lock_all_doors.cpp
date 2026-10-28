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

int n, r;
vector<int> L;

int left() {
  int ans = 0;

  int l = -1;
  for (int i = 0; i < r; i++)
    if (!L[i]) {
      l = i; // first door not locked.
      break;
    }

  // if -1, we don't need to lock any doors to our left
  if (l >= 0) {
    // how many doors do we need to flip unlocked until that door
    for (int i = l; i < r; i++)
      if (L[i])
        ans++;
    // go back to r, while flipping everything along the way.
    ans += r - l;
  }

  // same thing, find how much we need to go to our right
  int lim = -1;
  for (int i = n - 1; i >= r; i--)
    if (!L[i]) {
      lim = i;
      break;
    }

  // start heading right
  if (lim >= 0) {
    for (int i = r; i < lim; i++)
      if (L[i])
        ans += 2;
      else
        ans++;

    // at last door, we just need to lock last, don't need to move
    // so if it's already locked we don't do anything
    if (!L[lim])
      ans++;
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << setprecision(13);
  cin >> n >> r;
  L = vector<int>(n);
  rep(i, 0, n) cin >> L[i];

  int a = left();
  reverse(all(L));
  r = n - r;
  int b = left();

  cout << min(a, b) << el;
}
