#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int d, n;
  cin >> d >> n;
  vector<int> A(d + 1, 24);
  while (n--) {
    int l, r, h;
    cin >> l >> r >> h;
    for (int i = l; i <= r; i++)
      A[i] = min(A[i], h);
  }

  int ans = 0;
  for (int i = 1; i <= d; i++)
    ans += A[i];
  cout << ans << endl;
}
