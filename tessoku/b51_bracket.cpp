#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
  string s;
  cin >> s;
  stack<int> S;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(')
      S.push(i);
    else {
      int j = S.top();
      S.pop();
      cout << j + 1 << " " << i + 1 << "\n";
    }
  }
}
