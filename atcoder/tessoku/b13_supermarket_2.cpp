#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  ll n, k;
  cin >> n >> k;

  vector<ll> A(n + 1), S(n + 1), R(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> A[i];
  partial_sum(A.begin(), A.end(), S.begin());

  for (int i = 1; i <= n; i++) {
    int j = R[i - 1];
    while (j <= n && S[j] - S[i - 1] <= k)
      j++;
    R[i] = j;
  }

  ll s = 0;
  for (int i = 0; i <= n; i++)
    s += R[i] - i;
  cout << s << endl;
}
