#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<string> S(n);
    for (auto &&s : S)
        cin >> s;

    int x;
    string y;
    cin >> x >> y;
    cout << (S[x - 1] == y ? "Yes" : "No") << endl;
}
