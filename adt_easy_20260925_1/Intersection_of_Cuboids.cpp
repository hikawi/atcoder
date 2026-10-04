#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c, d, e, f;
    int g, h, i, j, k, l;
    cin >> a >> b >> c >> d >> e >> f;
    cin >> g >> h >> i >> j >> k >> l;

    // this is AABB 3D intersection, but its not that simple
    // i think
    if (a < j && d > g && b < k && e > h && c < l && f > i) {
        cout << "Yes\n";
    } else
        cout << "No\n";

    return 0;
}
