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

template <typename T> using uset = unordered_set<T>;
template <typename K, typename V> using umap = unordered_map<K, V>;
template <typename T, int N> using arr = array<T, N>;

#define rep(i, x, limit)   for (ll i = (ll)x; i < (ll)limit; i++)
#define repeq(i, x, limit) for (ll i = (ll)x; i <= (ll)limit; i++)
#define all(x)             x.begin(), x.end()
#define rall(x)            x.rbegin(), x.rend()
#define el                 '\n'
#define spa                " "
#define Yes                cout << "Yes" << el
#define No                 cout << "No" << el
#define YES                cout << "YES" << el
#define NO                 cout << "NO" << el
#define eps                (1e-10)
#define Equals(a, b)       (fabs((a) - (b)) < eps)
#define debug(x)           cerr << #x << "=" << x << el

const double pi = 3.141592653589793238;
const int inf = 1073741823;
const ll infl = 1LL << 60;
const ll modint = 998244353;
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

  ll n, q;
  cin >> n >> q;
  vector<ll> A(n + 1), S(n + 1), S2(n + 1), I(n + 1);
  repeq(i, 1, n) cin >> A[i];
  partial_sum(A.begin(), A.end(), S.begin());
  partial_sum(S.begin(), S.end(), S2.begin());
  iota(I.begin(), I.end(), 0);
  partial_sum(I.begin(), I.end(), I.begin());

  // print_vec(A);
  // print_vec(S);
  // print_vec(S2);
  // print_vec(I);

  auto getpartial = [&](const ll i) {
    auto it = upper_bound(I.begin(), I.end(), i) - I.begin() - 1;
    auto sure = S2[it];
    auto left = i - I[it];
    auto partial = S[left];

    // cout << "partial(" << i << ") = " << it << " -> " << sure << " + " << partial << el;

    return sure + partial;
  };

  rep(qi, 0, q) {
    ll l, r;
    cin >> l >> r;

    cout << getpartial(r) - getpartial(l - 1) << el;
  }
}
