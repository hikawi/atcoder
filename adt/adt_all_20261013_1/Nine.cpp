#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int a, b;
  cin >> a >> b;

  bool ans = false;
  switch (a) {
  case 1:
  case 2:
  case 4:
  case 5:
  case 7:
  case 8:
    ans = b == a + 1;
    break;
  }
  if (ans)
    cout << "Yes\n";
  else
    cout << "No\n";

  return 0;
}
