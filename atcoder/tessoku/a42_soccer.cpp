#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> A(n), B(n);
  for (int i = 0; i < n; i++)
    cin >> A[i] >> B[i];

  int ans = 0;
  for (int a = 1; a <= 100 - k; a++) {
    for (int b = 1; b <= 100 - k; b++) {
      int c = 0;
      for (int i = 0; i < n; i++)
        c += A[i] >= a && A[i] <= a + k && B[i] >= b && B[i] <= b + k;
      ans = max(ans, c);
    }
  }
  cout << ans << endl;
}
