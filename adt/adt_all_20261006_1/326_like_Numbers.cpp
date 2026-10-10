#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  for (int i = n; i <= 919; i++) {
    int a1, a2, a3;
    a3 = i % 10;
    a2 = (i / 10) % 10;
    a1 = i / 100;

    if (a1 * a2 == a3) {
      cout << i << endl;
      break;
    }
  }

  return 0;
}
