#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

bool isprime(int n) {
  if (n == 0)
    return false;
  if (n <= 2)
    return true;
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0)
      return false;
  return true;
}

int ans = -1;
unordered_map<char, int> assignment;
array<int, 10> used;

void dfs(string &s, int cur, int num) {
  if (cur >= s.length()) {
    if (isprime(num))
      ans = num;
    return;
  }

  if (ans != -1) {
    // 一つの答えでいい。
    return;
  }

  if (assignment.contains(s[cur])) {
    // すでにマッピングしたから同じを使う。
    int ass = assignment[s[cur]];
    dfs(s, cur + 1, num * 10 + ass);
    return;
  }

  // まだマッピングしていないから全部を試す。
  for (int i = 0; i <= 9; i++) {
    if (used[i])
      continue;
    if (cur == 0 && i == 0)
      continue; // 0が前頭に立てず
    assignment[s[cur]] = i;
    used[i] = 1;
    dfs(s, cur + 1, num * 10 + i);
    used[i] = 0;
    assignment.erase(s[cur]);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  dfs(s, 0, 0);
  cout << ans << "\n";

  return 0;
}
