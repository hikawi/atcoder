#include <iostream>
using namespace std;
using ll = long long;

ll A[109][109][109]{};

int main() {
  int n, q;
  cin >> n;
  for (int x = 1; x <= n; x++)
    for (int y = 1; y <= n; y++)
      for (int z = 1; z <= n; z++)
        cin >> A[x][y][z];

  for (int x = 1; x <= n; x++)
    for (int y = 1; y <= n; y++)
      for (int z = 1; z <= n; z++)
        A[x][y][z] += A[x][y][z - 1];

  for (int x = 1; x <= n; x++)
    for (int z = 1; z <= n; z++)
      for (int y = 1; y <= n; y++)
        A[x][y][z] += A[x][y - 1][z];

  for (int y = 1; y <= n; y++)
    for (int z = 1; z <= n; z++)
      for (int x = 1; x <= n; x++)
        A[x][y][z] += A[x - 1][y][z];

  cin >> q;
  while (q--) {
    int x1, y1, z1, x2, y2, z2;
    cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;
    x1--;
    y1--;
    z1--;

    ll a = A[x2][y2][z2];
    a = a - A[x2][y2][z1] - A[x2][y1][z2] - A[x1][y2][z2];
    a = a + A[x2][y1][z1] + A[x1][y2][z1] + A[x1][y1][z2];
    a = a - A[x1][y1][z1];
    cout << a << endl;
  }
}
