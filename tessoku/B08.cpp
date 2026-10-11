#include <iostream>
#include <vector>
int main() {
  using namespace std;
  int n;
  cin >> n;
  int w = 1500, h = 1500;

  vector<vector<int>> map(h);
  for (int i = 0; i < h; i++)
    map[i].resize(w);

  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    map[y - 1][x - 1] = 1;
  }

  // 二次元総和
  vector<vector<int>> wa(h + 1);
  wa[0].resize(w + 1);

  // 横
  for (int i = 1; i <= h; i++) {
    wa[i].resize(w + 1);
    for (int j = 1; j <= w; j++)
      wa[i][j] = wa[i][j - 1] + map[i - 1][j - 1];
  }

  // 縦
  for (int j = 1; j <= w; j++)
    for (int i = 1; i <= h; i++)
      wa[i][j] = wa[i - 1][j] + wa[i][j];

  // クエリ処理
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d; // (a,b) -> (c,d) (x, y型)
    cout << wa[d][c] - wa[b - 1][c] - wa[d][a - 1] + wa[b - 1][a - 1] << "\n";
  }
}
