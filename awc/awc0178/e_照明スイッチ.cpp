#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
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

#define rep(i, x, limit) for (ll i = (ll)x; i < (ll)limit; i++)
#define REP(i, x, limit) for (ll i = (ll)x; i <= (ll)limit; i++)
#define all(x)           x.begin(), x.end()
#define rall(x)          x.rbegin(), x.rend()
#define el               '\n'
#define spa              " "
#define Yes              cout << "Yes" << el
#define No               cout << "No" << el
#define YES              cout << "YES" << el
#define NO               cout << "NO" << el
#define eps              (1e-10)
#define Equals(a, b)     (fabs((a) - (b)) < eps)
#define debug(x)         cerr << #x << "=" << x << el

const double pi = 3.141592653589793238;
const int inf = 1073741823;
const ll infl = 1LL << 60;
const string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string abc = "abcdefghijklmnopqrstuvwxyz";

template <typename T1, typename T2> std::ostream &operator<<(std::ostream &os, std::pair<T1, T2> p) {
  os << "{" << p.first << "," << p.second << "}";
  return os;
}

// 配列の要素を空白区切りで出力 第二引数をtrueにすると改行区切り
template <typename T> inline void print_vec(const vector<T> &v, bool split_line = false) {
  if (v.empty()) {
    cout << "This vector is empty." << el;
    return;
  }
  constexpr bool isValue = is_integral<T>::value;
  for (int i = 0; i < (int)v.size(); i++) {
    if constexpr (isValue) {
      if ((v[i] == inf) || (v[i] == infl))
        cout << 'x' << " \n"[split_line || i + 1 == (int)v.size()];
      else
        cout << v[i] << " \n"[split_line || i + 1 == (int)v.size()];
    } else
      cout << v[i] << " \n"[split_line || i + 1 == (int)v.size()];
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

template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) {
  bool compare = a < b;
  if (compare)
    a = b;
  return compare;
}
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) {
  bool compare = a > b;
  if (compare)
    a = b;
  return compare;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << setprecision(13);

  int n, m, k;
  cin >> n >> m >> k;

  vector<pll> panels(m);
  rep(i, 0, m) {
    ll a = 0;
    rep(j, 0, n) {
      int b;
      cin >> b;
      a = (a << 1) | b;
    }
    ll c;
    cin >> c;
    panels[i] = pair(a, c);
  }

  vector<char> bad(1 << n, 0);
  rep(i, 0, k) {
    ll a = 0;
    rep(j, 0, n) {
      int f;
      cin >> f;
      a = (a << 1) | f;
    }
    bad[a] = 1;
  }

  // get end state
  ll end = 0;
  rep(i, 0, n) {
    end = (end << 1) | 1;
  }

  // dijkstra?
  bool flag = false;
  ull ans = infl;
  {
    priority_queue<pair<ll, ull>, vector<pair<ll, ull>>, greater<pair<ll, ull>>> open; // cost, cur
    vector<ll> dist(1 << n, infl);

    open.emplace(0, 0);
    dist[0] = 0;

    while (!open.empty()) {
      const auto [cost, cur] = open.top();
      open.pop();

      if (cost > dist[cur])
        continue;
      if (cur == end) {
        flag = true;
        chmin(ans, cost);
        break;
      }

      for (const auto &[sw, c] : panels) {
        const auto neighbor = sw ^ cur;
        if (bad[neighbor] || dist[neighbor] <= cost + c)
          continue;

        open.emplace(cost + c, neighbor);
        dist[neighbor] = cost + c;
      }
    }
  }

  if (!flag)
    cout << -1 << el;
  else
    cout << ans << el;
}
