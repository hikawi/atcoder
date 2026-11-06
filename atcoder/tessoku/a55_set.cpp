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
    if (t == 1) {
      S.insert(x);
    } else if (t == 2) {
      S.erase(x);
    } else {
      auto it = S.lower_bound(x);
      if (it == S.end())
        cout << -1 << "\n";
      else
        cout << *it << "\n";
    }
  }
}
