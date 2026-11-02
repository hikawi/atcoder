#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main() {
  int n, x;
  string a;
  cin >> n >> x >> a;
  queue<int> Q;
  Q.push(x - 1);
  a[x - 1] = '@';

  while (!Q.empty()) {
    int pos = Q.front();
    Q.pop();

    if (pos - 1 >= 0 && pos - 1 < n && a[pos - 1] == '.') {
      a[pos - 1] = '@';
      Q.push(pos - 1);
    }
    if (pos + 1 >= 0 && pos + 1 < n && a[pos + 1] == '.') {
      a[pos + 1] = '@';
      Q.push(pos + 1);
    }
  }

  cout << a << "\n";
}
