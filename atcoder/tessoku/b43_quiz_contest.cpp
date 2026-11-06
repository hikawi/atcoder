#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> A(n, m);
  for (int i = 0; i < m; i++) {
    int a;
    cin >> a;
    A[--a]--;
  }

  for (auto a : A)
    cout << a << "\n";
}
