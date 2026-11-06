#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main() {
  int q;
  cin >> q;
  queue<string> Q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      string s;
      cin >> s;
      Q.push(s);
    } else if (t == 2) {
      cout << Q.front() << "\n";
    } else {
      Q.pop();
    }
  }
}
