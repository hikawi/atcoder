#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll x, a, d, n;
    cin >> x >> a >> d >> n;

    if (d == 0) {
        cout << abs(x - a) << endl;
        return 0;
    }

    ll k = round(((double(x) - a) / d) + 1);
    k = clamp(k, 1ll, n);
    cout << abs(x - (a + d * (k - 1))) << endl;

    return 0;
}
