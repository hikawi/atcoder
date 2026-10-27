#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;
    s = "x" + s + "x";

    int c{};
    for (const auto it : s | views::slide(3)) {
        if (it[0] == it[1] && it[0] == it[2] && it[0] == 'x')
            c++;
    }
    cout << c << endl;

    return 0;
}
