#include <iostream>
int main() {
  using namespace std;
  int n, t;
  cin >> n >> t;

  int s = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (t - i - j >= 1 && t - i - j <= n)
        s++;
    }
  cout << s << "\n";
}
