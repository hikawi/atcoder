#include <bits/stdc++.h>
using namespace std;

struct Query {
    int type;
    union {
        int x;
        char c;
    };
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    vector<Query> Q(q + 1);
    vector<bool> B(n);
    Q[0].type = 2;
    Q[0].c = 'a';
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            cin >> x;
            B[x - 1] = !B[x - 1];
            Q[i + 1].type = 1;
            Q[i + 1].x = x;
        } else {
            char c;
            cin >> c;
            Q[i + 1].type = 2;
            Q[i + 1].c = c;
        }
    }

    unordered_set<int> untiled;
    for (const auto &[k, b] : B | views::enumerate) {
        if (!b)
            untiled.insert(k);
    }
    string S(n, ' ');

    for (const auto &q : Q | views::reverse) {
        if (q.type == 1) {
            const auto it = untiled.find(q.x - 1);
            if (it != untiled.end() && S[q.x - 1] == ' ') {
                untiled.erase(q.x - 1);
            } else if (it == untiled.end() && S[q.x - 1] == ' ') {
                untiled.insert(q.x - 1);
            }
        } else {
            for (const int i : untiled) {
                S[i] = q.c;
            }
            untiled.clear();
        }
    }

    cout << S << endl;
}
