#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  array<int, 9> A;
  rep(i, 9) cin >> A[i];
  vector<tuple<int, int, int>> row{{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6},
                                   {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

  array<int, 9> order;
  iota(order.begin(), order.end(), 0);

  // 自分が問題文こそわからなかったわけか
  // ProbabilityTheoryと思った
  ll sad = 0, all = 0;
  do {
    all++;
    bool bruh = false;
    for (const auto &[a, b, c] : row) {
      if (A[a] == A[b] && order[a] < order[c] && order[b] < order[c])
        bruh = true;
      else if (A[a] == A[c] && order[a] < order[b] && order[c] < order[b])
        bruh = true;
      else if (A[b] == A[c] && order[b] < order[a] && order[c] < order[a])
        bruh = true;
    }

    if (bruh)
      sad++;
  } while (next_permutation(order.begin(), order.end()));

  cout << setprecision(10);
  cout << double(all - sad) / all << endl;

  return 0;
}
