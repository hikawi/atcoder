#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)

struct node {
  int val;
  node *next = nullptr;
  node *prev = nullptr;

  node(int val) : val(val) {
  }

  void print() {
    cout << "(";
    if (prev)
      cout << prev->val << ",";
    else
      cout << "NULL,";
    cout << val << ",";
    if (next)
      cout << next->val << ")";
    else
      cout << "NULL)";
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<ll> A(n + 1);
  rep(i, n) cin >> A[i];
  sort(A.begin(), A.end());

  // make it into a doubly linked list probably
  node dummy(0);
  node *start = nullptr;
  node *tail = &dummy;
  for (const auto l : A) {
    tail->next = new node(l);
    tail->next->prev = tail;
    tail = tail->next;
    if (l == 0) {
      start = tail;
    }
  }

  // so now we can start.
  dummy.next->prev = nullptr;
  ll total = 0;

  while (start) {
    node *next = nullptr;

    if (!start->next && !start->prev) {
      break;
    } else if (!start->next) {
      // we have to move prev
      next = start->prev;
      next->next = nullptr;
    } else if (!start->prev) {
      // we have to move next
      next = start->next;
      next->prev = nullptr;
    } else {
      // pick
      ll d1 = abs(start->prev->val - start->val);
      ll d2 = abs(start->next->val - start->val);
      if (d1 <= d2) {
        next = start->prev;
        next->next = start->next;
        start->next->prev = next;
      } else {
        next = start->next;
        next->prev = start->prev;
        start->prev->next = next;
      }
    }

    total += abs(next->val - start->val);
    start = next;
  }

  cout << total << endl;

  return 0;
}
