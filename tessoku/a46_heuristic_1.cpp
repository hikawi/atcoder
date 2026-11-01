#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  int n;
  cin >> n;
  vector<ll> X(n), Y(n);
  for (int i = 0; i < n; i++)
    cin >> X[i] >> Y[i];

  auto dist = [&](int i, int j) { return sqrt((X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j])); };
  vector<int> path(n + 1);
  iota(path.begin(), path.end(), 0);
  path.back() = 0;

  auto randint = [&]() { return rand() % (n - 1) + 1; };

  // 山登り法
  for (int i = 0; i < 2000000; i++) {
    int x = randint(), y = randint();
    if (x > y)
      swap(x, y);

    double before = dist(path[x - 1], path[x]) + dist(path[y], path[y + 1]);
    double after = dist(path[x - 1], path[y]) + dist(path[x], path[y + 1]);
    if (after < before)
      reverse(path.begin() + x, path.begin() + y + 1);
  }

  for (auto a : path)
    cout << a + 1 << "\n";
}
