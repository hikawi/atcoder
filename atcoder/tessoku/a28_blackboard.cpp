#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long ans = 0;
  while (n--) {
    char t;
    long long a;
    cin >> t >> a;
    switch (t) {
    case '+':
      ans += a;
      break;
    case '-':
      ans -= a;
      break;
    case '*':
      ans *= a;
      break;
    }
    ans %= 10000;
    if (ans < 0)
      ans += 10000;
    cout << ans << endl;
  }
}
