#include <algorithm>
#include <iostream>
#include <string>
int main() {
  using namespace std;
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  int n = 0;
  while (s.length() > 0) {
    char c = s.back();
    n <<= 1;
    if (c == '1')
      n |= 1;
    s.pop_back();
  }

  cout << n << "\n";
}
