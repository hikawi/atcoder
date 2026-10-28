#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <map>
#include <ranges>
#include <set>
#include <unordered_map>
#include <unordered_set>
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
template <typename T1, typename T2> std::ostream &operator<<(std::ostream &os, std::pair<T1, T2> p) {os << "{" << p.first << "," << p.second << "}";return os;}
// 配列の要素を空白区切りで出力 第二引数をtrueにすると改行区切り
template <typename T> inline void print_vec(const vector<T> &v, bool split_line = false) {
  if (v.empty()) {
    cout << "This vector is empty." << el;
    return;
  }
  constexpr bool isValue = is_integral<T>::value;
  for (int i = 0; i < (int)v.size(); i++) {
    if constexpr (isValue) {
      if ((v[i] == inf) || (v[i] == infl)) cout << 'x' << " \n"[split_line || i + 1 == (int)v.size()];
      else cout << v[i] << " \n"[split_line || i + 1 == (int)v.size()];
    } else cout << v[i] << " \n"[split_line || i + 1 == (int)v.size()];
  }
}

template <typename T1, typename T2> inline void print_vec(const vector<pair<T1, T2>> &v, bool split_line = false) {
  if (v.empty()) {
    cout << "This vector is empty." << el;
    return;
  }
  for (int i = 0; i < (int)v.size(); i++) {
    cout << '{';
    auto [a, b] = v[i];
    constexpr pair<bool, bool> isValue = {is_integral<T1>::value, is_integral<T2>::value};
    if constexpr (isValue.first) {
      if (a == inf || a == infl)
        cout << "x,";
      else
        cout << a << ",";
    } else
      cout << a << ",";
    if constexpr (isValue.second) {
      if (b == inf || b == infl)
        cout << "x,";
      else
        cout << b;
    } else
      cout << b;
    cout << "}" << " \n"[split_line || i + 1 == (int)v.size()];
  }
}
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) {bool compare = a < b;if (compare)a = b;return compare;}
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) {bool compare = a > b;if (compare)a = b;return compare;}
// clang-format on

vector<string> T;
string s;

void build(int v, int l, int r) {
  if (l == r) {
    T[v] = s[l];
  } else {
    int m = (l + r) / 2;
    build(v * 2, l, m);
    build(v * 2 + 1, m + 1, r);
    T[v] = T[v * 2] + T[v * 2 + 1];
  }
}

void update(int v, int l, int r, int i, char c) {
  if (l == r) {
    T[v] = c;
  } else {
    int m = (l + r) / 2;
    if (i <= m)
      update(2 * v, l, m, i, c);
    else
      update(2 * v + 1, m + 1, r, i, c);
    T[v] = T[v * 2] + T[v * 2 + 1];
  }
}

string query(int v, int l, int r, int ul, int ur) {
  if (r < ul || l > ur)
    return "";
  if (l >= ul && r <= ur)
    return T[v];

  int m = (l + r) / 2;
  return query(2 * v, l, m, ul, ur) + query(2 * v + 1, m + 1, r, ul, ur);
}

bool palin(string &s) {
  int i = 0, j = s.length() - 1;
  while (i < j) {
    if (s[i++] != s[j--])
      return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << setprecision(13);

  int n, q;
  cin >> n >> q >> s;

  T = vector<string>(4 * n + 1);
  build(1, 0, n - 1);

  rep(qi, 0, q) {
    int i;
    cin >> i;

    if (i == 1) {
      int x;
      char c;
      cin >> x >> c;
      x--;
      update(1, 0, n - 1, x, c);
    } else {
      int l, r;
      cin >> l >> r;
      l--;
      r--;
      string s = query(1, 0, n - 1, l, r);
      if (palin(s))
        Yes;
      else
        No;
    }
  }
}
