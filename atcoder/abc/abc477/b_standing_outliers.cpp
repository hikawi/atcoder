#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> A(n);
    for (auto &&a : A)
        cin >> a;

    int c = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        bool apart = true;
        for (int j = 0; j < n; j++) {
            if (j == i)
                continue;
            if (abs(A[i] - A[j]) < d) {
                apart = false;
                break;
            }
        }

        if (apart) {
            c++;
            ans.push_back(i + 1);
        }
    }

    cout << c << endl;
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
}
