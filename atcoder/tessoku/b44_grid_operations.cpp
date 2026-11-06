#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<vector<int>> A(n, vector<int>(n));
  vector<int> rows(n); // row i -> dest row
  iota(rows.begin(), rows.end(), 0);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> A[i][j];

  int q;
  cin >> q;
  while (q--) {
    int t, x, y;
    cin >> t >> x >> y;
    x--;
    y--;
    if (t == 1) {
      int tmp = rows[x];
      rows[x] = rows[y];
      rows[y] = tmp;
    } else {
      int i = rows[x];
      cout << A[i][y] << "\n";
    }
  }
}
