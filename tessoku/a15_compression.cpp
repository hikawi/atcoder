#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
int main() {
  using namespace std;
  using ll = long long;
  int n;
  cin >> n;
  vector<ll> A(n), S;
  unordered_set<ll> M;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    if (!M.count(A[i])) {
      M.insert(A[i]);
      S.push_back(A[i]);
    }
  }
  sort(S.begin(), S.end());
  for (const auto a : A) {
    auto i = lower_bound(S.begin(), S.end(), a) - S.begin();
    cout << i + 1 << " ";
  }
  cout << "\n";
}
