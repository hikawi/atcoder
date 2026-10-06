#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)

struct candidate {
  int votes;
  int no;

  candidate(int votes, int no) : votes(votes), no(no) {
  }

  bool operator=(const candidate &c) const {
    return votes == c.votes && no == c.no;
  }

  bool operator<(const candidate &c) const {
    if (c.votes == votes) {
      return no > c.no;
    } else
      return votes < c.votes;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  set<candidate> pq;    // pair(votes, number)
  vector<int> votes(n); // map number -> votes
  rep(i, n) pq.insert(candidate(0, i + 1));

  rep(i, m) {
    int v;
    cin >> v;

    pq.erase({votes[v - 1], v});
    votes[v - 1]++;
    pq.insert({votes[v - 1], v});

    // new
    cout << pq.rbegin()->no << "\n";
  }

  return 0;
}
