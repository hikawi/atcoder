#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
int main() {
  int n, q;
  cin >> n >> q;
  vector<int> A(n);
  int rev = 0;
  iota(A.begin(), A.end(), 1);
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, y;
      cin >> x >> y;
      x--;
      if (rev)
        A[n - 1 - x] = y;
      else
        A[x] = y;
    } else if (t == 2) {
      rev = !rev;
    } else {
      int x;
      cin >> x;
      x--;
      if (rev)
        cout << A[n - 1 - x] << "\n";
      else
        cout << A[x] << "\n";
    }
  }
}
