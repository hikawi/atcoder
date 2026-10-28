#include <iostream>
using namespace std;
int main() {
  long long n;
  cin >> n;
  cout << (n / 3 + n / 5 + n / 7 - n / 15 - n / 21 - n / 35 + n / 105) << endl;
}
