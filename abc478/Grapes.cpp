#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);

  int p = 0;
  for (int i = 0; i < m; i++) {
    a[p]++;
    p = (p + 1) % n;
  }

  for (int i = 0; i < n; i++)
    cout << a[i] << endl;
}