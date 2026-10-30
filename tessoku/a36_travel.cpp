#include <iostream>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  if (k >= 2 * (n - 1) && k % 2 == 0)
    cout << "Yes\n";
  else
    cout << "No\n";
}
