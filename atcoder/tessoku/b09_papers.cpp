#include <iostream>

int grid[1501][1501];
int wa[1501][1501];

int main() {
  using namespace std;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    grid[b][a]++;
    grid[b][c]--;
    grid[d][a]--;
    grid[d][c]++;
  }

  for (int i = 1; i <= 1500; i++)
    for (int j = 1; j <= 1500; j++)
      wa[i][j] = wa[i][j - 1] + grid[i - 1][j - 1];

  for (int i = 1; i <= 1500; i++)
    for (int j = 1; j <= 1500; j++)
      wa[i][j] += wa[i - 1][j];

  // for (int i = 0; i < 7; i++) {
  //   for (int j = 0; j < 7; j++)
  //     cout << wa[i][j] << " ";
  //   cout << "\n";
  // }

  long long s = 0;
  for (int i = 0; i <= 1500; i++)
    for (int j = 0; j <= 1500; j++)
      s += wa[i][j] >= 1;
  cout << s << "\n";
}
