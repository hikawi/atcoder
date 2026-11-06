#include <iostream>
#include <string>
int main() {
  using namespace std;
  using ll = long long;
  int n;
  string s;
  cin >> n >> s;
  array<int, 10> freq{};
  for (const auto c : s)
    freq[c - '0']++;

  // 10^13 max => n^7
  ll c = 0;
  for (ll i = 0;; i++) {
    ll a = i * i, len = 0;
    array<int, 10> f{};
    while (a) {
      f[a % 10]++;
      a /= 10;
      len++;
    }

    if (len > n)
      break;

    f[0] = n - len;
    bool flag = true;
    for (int j = 1; j <= 9; j++)
      if (f[j] != freq[j]) {
        flag = false;
        break;
      }

    c += flag;
  }
  cout << c << endl;
}
