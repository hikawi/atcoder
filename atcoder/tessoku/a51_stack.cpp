#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
  int q;
  cin >> q;
  stack<string> S;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      string s;
      cin >> s;
      S.push(s);
    } else if (t == 2) {
      cout << S.top() << "\n";
    } else {
      S.pop();
    }
  }
}
