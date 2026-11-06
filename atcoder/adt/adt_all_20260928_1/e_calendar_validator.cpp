#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int **B = new int *[n];
    int **M = new int *[n];
    int **R = new int *[n];

    rep(i, n) {
        B[i] = new int[m];
        M[i] = new int[m];
        R[i] = new int[m];
        rep(j, m) {
            cin >> B[i][j];
            B[i][j]--;
            M[i][j] = B[i][j] % 7;
            R[i][j] = B[i][j] / 7;
        }
    }

    // it's a part if each row sliding is
    rep(i, n) {
        rep(j, m - 1) {
            if (B[i][j] != B[i][j + 1] - 1 || M[i][j] != M[i][j + 1] - 1) {
                cout << "No\n";
                return 0;
            }
        }
    }

    rep(j, m) {
        rep(i, n - 1) {
            if (B[i][j] != B[i + 1][j] - 7 || R[i][j] != R[i + 1][j] - 1) {
                cout << "No\n";
                return 0;
            }
        }
    }

    cout << "Yes\n";
    return 0;
}
