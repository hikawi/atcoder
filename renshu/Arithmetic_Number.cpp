#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
using ll = long long;

set<ll> an;

void gen(ll len = 0, ll cur = 0) {
  if (len > 18) {
    return;
  }

  if (cur)
    an.insert(cur);

  // 差がまだない
  if (len <= 1) {
    // 頭に０をつけず
    for (int i = (len == 0); i <= 9; i++) {
      gen(len + 1, cur * 10 + i);
    }
    return;
  }

  // これからはいつも２以上だから差が求められる
  int fi = cur / 10 % 10, si = cur % 10;
  int diff = si - fi;
  for (int i = 0; i <= 9; i++) {
    if (diff + si == i)
      gen(len + 1, cur * 10 + i);
  }
}

int main() {
  ll x;
  cin >> x;

  gen();

  auto it = lower_bound(an.begin(), an.end(), x);
  cout << *it << endl;

  // for (const auto a : an)
  //   cout << a << " ";
  // cout << endl;
}
