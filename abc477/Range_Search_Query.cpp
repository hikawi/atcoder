#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    string s, t;
    cin >> s >> t;

    vector<int> A(s.length()), P(s.length());
    for (int i = 0; i < s.length() - t.length() + 1; i++) {
        if (s.substr(i, t.length()) == t) {
            A[i] = 1;
            if (i != 0)
                P[i] = P[i - 1] + 1;
        } else if (i != 0)
            P[i] = P[i - 1];
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        if (P[r - t.length()] - P[l - 2] >= 1)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
