#include <iostream>
using namespace std;
using ll = long long;
int main() {
  int n;
  cin >> n;
  int C[100]{};
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    C[a % 100]++;
  }

  ll ans = 0;
  for (int i = 1; i < 50; i++)
    ans += (C[i] * C[100 - i]);

  // special for 0 and 50
  if (C[0])
    ans += (C[0] * (C[0] - 1)) / 2;
  if (C[50])
    ans += (C[50] * (C[50] - 1)) / 2;
  cout << ans << endl;
}
