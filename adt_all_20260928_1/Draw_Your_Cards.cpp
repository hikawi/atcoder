#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)

struct node {
    int val = 0;
    int length = 0;
    node *next = nullptr;

    node(int val) : val(val) {
        length = 1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> eat(n, -1);
    deque<node *> piles;
    rep(i, n) {
        int p;
        cin >> p;

        if (k == 1) {
            eat[p - 1] = i + 1;
            continue;
        }

        // find
        node *new_node = new node(p);
        if (piles.empty()) {
            // cout << "empty, push back " << p << endl;
            piles.push_back(new_node);
            continue;
        }

        auto it = upper_bound(piles.begin(), piles.end(), new_node,
                              [&](const auto a, const auto b) { return a->val < b->val; });
        if (it == piles.end()) {
            piles.insert(it, new_node);
            continue;
        }

        // There is an upperbound.
        // cout << "found upper bound " << p << ": " << (*it)->val << endl;
        new_node->next = *it;
        new_node->length = (*it)->length + 1;

        // can we eat it?
        if (new_node->length >= k) {
            // eat
            node *cur = new_node;
            while (cur) {
                eat[cur->val - 1] = i + 1;
                cur = cur->next;
            }
            piles.erase(it);
        } else {
            // replace
            *it = new_node;
        }
    }

    for (int c : eat)
        cout << c << endl;

    return 0;
}
