#include <iostream>
#include <vector>
int main() {
  using namespace std;
  int n, q;
  cin >> n >> q;
  vector<int> A(n), S(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    S[i + 1] = S[i] + A[i];
  }

  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    cout << S[r] - S[l - 1] << "\n";
  }
}
