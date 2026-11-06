#include <algorithm>
#include <iostream>
#include <vector>
int main() {
  using namespace std;
  int n;
  cin >> n;
  vector<int> A(n), B(n), C(n);
  for (int i = 0; i < n; i++)
    cin >> A[i];

  B[0] = A[0];
  C[n - 1] = A[n - 1];
  for (int i = 1; i < n; i++)
    B[i] = max(B[i - 1], A[i]);
  for (int i = n - 2; i >= 0; i--)
    C[i] = max(C[i + 1], A[i]);

  int d;
  cin >> d;
  for (int di = 0; di < d; di++) {
    int a, b;
    cin >> a >> b;
    cout << max(B[a - 2], C[b]) << "\n";
  }
}
