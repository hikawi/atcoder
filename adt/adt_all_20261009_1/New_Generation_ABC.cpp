#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  if (n <= 125) {
    cout << 4 << endl;
  } else if (n <= 211) {
    cout << 6 << endl;
  } else
    cout << 8 << endl;

  return 0;
}
