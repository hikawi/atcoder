#include <iostream>
#include <string>
using namespace std;
int main() {
  int n;
  char c;
  string s;
  cin >> n >> c >> s;

  int sum = 0;
  for (auto c : s)
    if (c == 'B')
      sum += 1;
    else if (c == 'R')
      sum += 2;

  int mod = c == 'B' ? 1 : c == 'R' ? 2 : 0;
  if (sum % 3 == mod)
    cout << "Yes\n";
  else
    cout << "No\n";
}
