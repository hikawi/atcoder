#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> A(n);
  for (int i = 0; i < n; i++)
    cin >> A[i];

  vector<ll> H;
  H.reserve(1 << (n / 2));
  for (int i = 0; i < 1 << (n / 2); i++) {
    ll a = 0, cur = i;
    for (int j = 0; j < n / 2; j++) {
      if (cur & 1)
        a += A[j];
      cur >>= 1;
    }

    H.push_back(a);
  }
  sort(H.begin(), H.end());

  // 後半ビット全探索
  for (int i = 0; i < 1 << (n - n / 2); i++) {
    ll a = 0, cur = i;
    for (int j = n / 2; j < n; j++) {
      if (cur & 1)
        a += A[j];
      cur >>= 1;
    }

    if (a == k || binary_search(H.begin(), H.end(), k - a)) {
      cout << "Yes\n";
      return 0;
    }
  }

  cout << "No\n";
}
