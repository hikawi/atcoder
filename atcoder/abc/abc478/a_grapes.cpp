#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int v = m / n + (m % n > i);
        cout << v << endl;
    }
}
