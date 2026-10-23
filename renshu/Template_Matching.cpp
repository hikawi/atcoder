#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m;

bool matches(int i, int j, vector<string> &G, vector<string> &T) {
  if (i + m > n || j + m > n)
    return false;

  for (int a = 0; a < m; a++) {
    for (int b = 0; b < m; b++) {
      if (G[i + a][j + b] != T[a][b])
        return false;
    }
  }
  return true;
}

int main() {
  cin >> n >> m;
  vector<string> G(n);
  for (int i = 0; i < n; i++)
    cin >> G[i];

  vector<string> T(m);
  for (int i = 0; i < m; i++)
    cin >> T[i];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (matches(i, j, G, T)) {
        cout << "Yes\n";
        return 0;
      }
    }
  }

  cout << "No\n";
}
