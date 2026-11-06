#include <iostream>
#include <vector>

int main() {
  using namespace std;
  int h, w, n;
  cin >> h >> w >> n;

  vector<vector<int>> yuki(h + 1);
  yuki[0].resize(w + 1);
  for (int i = 1; i <= h; i++) {
    yuki[i].resize(w + 1);
  }

  for (int i = 0; i < n; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    yuki[a - 1][b - 1]++;
    yuki[a - 1][d]--;
    yuki[c][b - 1]--;
    yuki[c][d]++;
  }

  // 累積横
  for (int i = 0; i <= h; i++)
    for (int j = 1; j <= w; j++)
      yuki[i][j] += yuki[i][j - 1];

  // 累積縦
  for (int i = 1; i <= h; i++)
    for (int j = 0; j <= w; j++)
      yuki[i][j] += yuki[i - 1][j];

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++)
      cout << yuki[i][j] << " ";
    cout << "\n";
  }
}
