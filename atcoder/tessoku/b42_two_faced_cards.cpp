#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  int n;
  cin >> n;
  vector<ll> A(n), B(n);
  for (int i = 0; i < n; i++)
    cin >> A[i] >> B[i];

  ll ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
  for (int i = 0; i < n; i++) {
    if (A[i] + B[i] > 0)
      ans1 += A[i] + B[i];
    if (A[i] - B[i] > 0)
      ans2 += A[i] - B[i];
    if (-A[i] + B[i] > 0)
      ans3 += B[i] - A[i];
    if (-A[i] - B[i] > 0)
      ans4 += -A[i] - B[i];
  }

  cout << max(ans1, max(ans2, max(ans3, ans4))) << endl;
}
