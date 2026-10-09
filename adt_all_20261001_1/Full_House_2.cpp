#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  unordered_set<int> s;
  s.insert(a);
  s.insert(b);
  s.insert(c);
  s.insert(d);

  if (s.size() == 2)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
