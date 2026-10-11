#include <iostream>
int main() {
  using namespace std;
  int n, x;
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a == x) {
      cout << "Yes\n";
      return 0;
    }
  }

  cout << "No\n";
}
