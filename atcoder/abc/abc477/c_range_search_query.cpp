#include <bits/stdc++.h>
using namespace std;

void printv(vector<int> &v) {
    for (int i : v)
        cout << i << " ";
    cout << endl;
}

int main() {
    int q;
    cin >> q;
    string s, t;
    cin >> s >> t;

    vector<int> A(s.length()), P(s.length());
    for (size_t i = 0; i < s.length(); i++) {
        if (s.substr(i, t.length()) == t) {
            A[i] = 1;
            if (i != 0)
                P[i] = P[i - 1] + 1;
            else
                P[i] = A[i];
        } else if (i != 0)
            P[i] = P[i - 1];
    }

    // printv(P);

    P.insert(P.begin(), 0);

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        // cout << "l=" << l << ",r=" << r;

        if (r - l + 1 < t.length() || r - int(t.length()) < 0) {
            cout << "No\n";
            continue;
        }

        int pr = P[r - t.length() + 1];
        int pl = P[l - 1];
        cout << (pr - pl > 0 ? "Yes\n" : "No\n");

        // bool found = false;
        // for (int j = l - 1; j <= r - t.length(); j++)
        //     if (A[j]) {
        //         found = true;
        //         break;
        //     }
        // cout << (found ? "Yes" : "No") << endl;
    }
}
