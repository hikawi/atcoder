#include <iostream>
#include <vector>
int main() {
  using namespace std;
  int n;
  cin >> n;
  vector<int> A(n);
  for (auto &&a : A)
    cin >> a;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        if (A[i] + A[j] + A[k] == 1000) {
          cout << "Yes\n";
          return 0;
        }
      }
    }
  }
  cout << "No\n";
}
