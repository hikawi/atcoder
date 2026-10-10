#include <deque>
#include <ios>
#include <iostream>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  deque<pair<int, int>> S;
  int sum = 0;

  rep(i, n) {
    int a;
    cin >> a;

    if (S.empty()) {
      S.emplace_back(a, 1);
      sum += 1;
    } else {
      auto &p = S.back();
      if (p.first == a && p.second + 1 >= a) {
        sum -= p.second;
        S.pop_back();
      } else if (p.first == a) {
        p.second++;
        sum += 1;
      } else {
        S.emplace_back(a, 1);
        sum += 1;
      }
    }

    cout << sum << "\n";
  }

  return 0;
}
