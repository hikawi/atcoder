#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        A[i] = i + 1;

    int rot = 0;
    for (int i = 0; i < q; i++) {
        int type, p, x, k;
        cin >> type;
        switch (type) {
        case 1:
            cin >> p >> x;
            A[(p + rot - 1) % n] = x;
            break;
        case 2:
            cin >> p;
            cout << A[(p + rot - 1) % n] << endl;
            break;
        case 3:
            cin >> k;
            rot = (rot + k) % n;
            break;
        }
    }

    return 0;
}
