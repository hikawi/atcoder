#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  cin >> n;

  if (n == 1) {
    cout << "Not Prime\n";
    return 0;
  }
  if (n == 2 || n == 3 || n == 5) {
    cout << "Prime\n";
    return 0;
  }

  if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0) {
    cout << "Not Prime\n";
    return 0;
  } else {
    cout << "Prime\n";
  }
  return 0;
}
