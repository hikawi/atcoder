#include <algorithm>
#include <iostream>
#include <vector>
int main() {
  using namespace std;
  using ll = long long;
  ll n, k;
  cin >> n >> k;
  vector<ll> A(n), B(n), C(n), D(n);
  for (int i = 0; i < n; i++)
    cin >> A[i];
  for (int i = 0; i < n; i++)
    cin >> B[i];
  for (int i = 0; i < n; i++)
    cin >> C[i];
  for (int i = 0; i < n; i++)
    cin >> D[i];

  vector<ll> CD;
  CD.reserve(n * n);
  for (int c = 0; c < n; c++) {
    for (int d = 0; d < n; d++) {
      ll cd = C[c] + D[d];
      CD.push_back(cd);
    }
  }
  sort(CD.begin(), CD.end());

  for (int a = 0; a < n; a++) {
    for (int b = 0; b < n; b++) {
      ll ab = A[a] + B[b];
      if (binary_search(CD.begin(), CD.end(), k - ab)) {
        cout << "Yes\n";
        return 0;
      }
    }
  }
  cout << "No\n";
}
