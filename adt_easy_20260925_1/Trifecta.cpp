#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> T(n);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        T[i] = pair(i + 1, t);
    }

    sort(T.begin(), T.end(), [&](auto a, auto b) { return a.second < b.second; });
    for (const auto h : T | views::take(3))
        cout << h.first << " ";
}
