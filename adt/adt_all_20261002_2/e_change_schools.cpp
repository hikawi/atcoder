#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int *A = new int[n];
  for (int i = 0; i < n; i++)
    cin >> A[i];

  int *C = new int[k]; // class -> count
  for (int i = 0; i < n; i++) {
    C[A[i] - 1]++;
  }

  int m = 0;
  for (int i = 0; i < k; i++)
    m = max(C[i], m);

  int c = 0;
  for (int i = 0; i < k; i++)
    if (C[i] >= m - 1)
      c++;
  cout << c << endl;
}
