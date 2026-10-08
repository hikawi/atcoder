#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  char map[128] = {};
  map[')'] = '(';
  map[']'] = '[';
  map['>'] = '<';

  stack<char> st;
  for (const char c : s) {
    if (c == '(' || c == '[' || c == '<')
      st.push(c);
    else {
      if (st.empty()) {
        cout << "No\n";
        return 0;
      }
      if (st.top() != map[c]) {
        cout << "No\n";
        return 0;
      } else
        st.pop();
    }
  }

  cout << (st.empty() ? "Yes\n" : "No\n");

  return 0;
}
