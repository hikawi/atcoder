#include <algorithm>
#include <array>
#include <atcoder/all>
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
using namespace atcoder;

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
vector<int> A;

struct S {
  ll val;
  int size;
  int max;
};

S op(S l, S r) {
  return S{l.val + r.val, l.size + r.size, max(l.max, r.max)};
}

S e() {
  return S{0, 0, 0};
}

S mapping(ll f, S x) {
  if (x.max <= f)
    return S{0, x.size, 0};
  else
    return S{};
}

ll composition(ll f, ll g) {
  return f + g;
}

ll id() {
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << setprecision(13);
  cin >> n;
  A = vector<int>(n);
  rep(i, 0, n) cin >> A[i];

  vector<S> init(n);
  rep(i, 0, n) {
    init[i] = S{A[i], 1};
  }

  lazy_segtree<S, op, e, ll, mapping, composition, id> seg(init);

  int q;
  cin >> q;
  while (q--) {
    int l, r, k;
    cin >> l >> r >> k;
    l--;
    auto b = seg.prod(l, r);
    seg.apply(l, r, k);
    auto a = seg.prod(l, r);
    cout << (b.val - a.val) << el;
  }
}
