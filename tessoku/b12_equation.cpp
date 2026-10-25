#include <cmath>
#include <iostream>

double eps = 1e-3;

bool feq(double a, double b) {
  return abs(a - b) <= eps;
}

double f(double x) {
  return pow(x, 3) + x;
}

int main() {
  using namespace std;
  int n;
  cin >> n;

  double l = 0, r = n;
  while (abs(r - l) > eps) {
    double mid = (l + r) / 2;
    double res = f(mid);

    // cout << l << "," << mid << "," << r << " -> " << res << endl;
    if (res < n)
      l = mid;
    else
      r = mid;
  }

  cout << (l + r) / 2 << endl;
}
