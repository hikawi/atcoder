#include <cstdlib>
#include <iostream>
#include <set>
using namespace std;
int main() {
  int q;
  cin >> q;
  set<int> S;
  while (q--) {
    int t, x;
    cin >> t >> x;
    if (t == 1)
      S.insert(x);
    else {
      auto it = S.lower_bound(x);

      bool f = 0;
      int ans = 1 << 30;
      if (it != S.end()) {
        ans = min(ans, abs(*it - x));
        f = 1;
      }
      if (it != S.begin()) {
        it--;
        ans = min(ans, abs(*it - x));
        f = 1;
      }

      cout << (f ? ans : -1) << "\n";
    }
  }
}
