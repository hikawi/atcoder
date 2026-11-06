#include <iostream>
int main() {
  using namespace std;
  int a, b;
  cin >> a >> b;

  for (int i = a; i <= b; i++)
    if (100 % i == 0) {
      cout << "Yes\n";
      return 0;
    }

  cout << "No\n";
}
