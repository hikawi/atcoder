#include <array>
#include <iostream>
using namespace std;
using ll = long long;
int main() {
  ll n;
  cin >> n;

  ll mul[16] = {1};
  for (int i = 1; i <= 15; i++)
    mul[i] = mul[i - 1] * 10;

  ll ans = 0;
  array<ll, 10> C{};
  for (int i = 0; i <= 14; i++) {
    int d = (n / mul[i]) % 10;
    for (int j = 0; j <= 9; j++) {
      if (j < d)
        C[j] += (n / mul[i + 1]) * mul[i] + mul[i];
      else if (j == d)
        C[j] += (n / mul[i + 1]) * mul[i] + (n % mul[i] + 1);
      else
        C[j] += (n / mul[i + 1]) * mul[i];
    }
  }

  for (int i = 0; i <= 9; i++)
    ans += C[i] * i;

  cout << ans << endl;
}
