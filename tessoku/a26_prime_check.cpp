#include <cmath>
#include <iostream>
using namespace std;
int main() {
  int q;
  cin >> q;

  auto isprime = [](int x) {
    if (x <= 2)
      return true;
    if (x % 2 == 0)
      return false;
    for (int i = 3; i <= sqrt(x) + 1; i += 2) {
      if (x % i == 0)
        return false;
    }
    return true;
  };

  while (q--) {
    int x;
    cin >> x;
    if (isprime(x))
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}
