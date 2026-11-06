#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, v;
  cin >> n >> v;
  vector<int> w(n);
  for (int i = 0; i < n; i++)
    cin >> w[i];

  int m = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        if (i + j + k > v - 3)
          continue;
        m = max(m, w[i] + w[j] + w[k]);
      }
    }
  }

  cout << m << endl;
}