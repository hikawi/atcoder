#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  vector<vector<int>> C(300009);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    C[A[i]].push_back(i);
  }

  int c = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        if (A[i] == A[k] && A[i] != A[j])
          c++;
      }
    }
  }
  cout << c << endl;
}
