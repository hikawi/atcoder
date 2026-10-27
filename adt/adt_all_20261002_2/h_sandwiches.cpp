#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int *A = new int[n];
  for (int i = 0; i < n; i++)
    cin >> A[i];

  int c = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        if (A[i] == A[k] && A[i] != A[j])
          c++;
      }
    }
  }
  cout << c << endl;
}
