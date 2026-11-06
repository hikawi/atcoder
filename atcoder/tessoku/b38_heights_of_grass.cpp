#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
string s;
vector<int> G;

int main() {
  cin >> n >> s;
  G = vector<int>(n, 1);

  for (int i = 0; i < n - 1; i++)
    if (s[i] == 'A')
      G[i + 1] = G[i] + 1;
  for (int i = n - 1; i > 0; i--)
    if (s[i - 1] == 'B')
      G[i - 1] = max(G[i - 1], G[i] + 1);

  int ans = 0;
  for (auto a : G)
    ans += a;
  cout << ans << endl;
}
