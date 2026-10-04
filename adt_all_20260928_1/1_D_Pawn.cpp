#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, q;
    cin >> n >> k >> q;
    vector<bool> spaces(n);
    vector<int> pawns(k);
    rep(i, k) {
        cin >> pawns[i];
        spaces[pawns[i] - 1] = true;
    }

    rep(i, q) {
        int l;
        cin >> l;

        if (pawns[l - 1] == n)
            continue;
        if (spaces[pawns[l - 1]])
            continue;

        spaces[pawns[l - 1] - 1] = false;
        spaces[pawns[l - 1]] = true;
        pawns[l - 1]++;
    }

    rep(i, k) {
        cout << (i == 0 ? "" : " ") << pawns[i];
    }
    cout << endl;

    return 0;
}
