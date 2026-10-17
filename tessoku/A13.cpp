#include <iostream>
#include <vector>
using ll = long long;
int main() {
  using namespace std;
  int n, k;
  cin >> n >> k;
  vector<int> A(n), C(n);
  for (int i = 0; i < n; i++)
    cin >> A[i];

  ll c = 0;
  for (int i = 0; i < n; i++) {
    int j = i == 0 ? 1 : C[i - 1];
    while (j < n && A[j] - A[i] <= k)
      j++;
    C[i] = j;
  }

  for (int i = 0; i < n; i++) {
    c += (C[i] - i - 1);
  }
  cout << c << endl;
}
