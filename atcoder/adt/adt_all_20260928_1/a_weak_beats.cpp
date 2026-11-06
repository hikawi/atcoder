#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    rep(i, s.length()) if (i % 2 == 1 && s[i] == '1') {
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n";
    return 0;
}
