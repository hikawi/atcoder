#include <iostream>
#include <vector>
int main() {
  using namespace std;
  int h, w;
  cin >> h >> w;
  vector<vector<int>> A(h);
  for (int i = 0; i < h; i++) {
    A[i].resize(w);
    for (int j = 0; j < w; j++)
      cin >> A[i][j];
  }

  // 二次元累積和配列
  vector<vector<int>> B(h + 1);
  B[0].resize(w + 1);
  for (int i = 1; i <= h; i++) {
    B[i].resize(w + 1);
    for (int j = 1; j <= w; j++)
      B[i][j] = A[i - 1][j - 1] + B[i][j - 1];
  }

  for (int j = 1; j <= w; j++)
    for (int i = 1; i <= h; i++)
      B[i][j] = B[i - 1][j] + B[i][j];

  // for (int i = 1; i <= h; i++) {
  //   for (int j = 1; j <= w; j++)
  //     cout << B[i][j] << " ";
  //   cout << "\n";
  // }

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int res = B[c][d] - B[c][b - 1] - B[a - 1][d] + B[a - 1][b - 1];
    cout << res << "\n";
  }
}
