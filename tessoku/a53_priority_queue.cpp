#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
int main() {
  int q;
  cin >> q;
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      ll x;
      cin >> x;
      pq.push(x);
    } else if (t == 2) {
      cout << pq.top() << "\n";
    } else {
      pq.pop();
    }
  }
}
