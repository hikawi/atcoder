#include <iostream>
#include <string>
using namespace std;
int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;

  int c = 0;
  for (auto ch : s)
    if (ch == '1')
      c++;

  if (c % 2 == k % 2)
    cout << "Yes\n";
  else
    cout << "No\n";
}
