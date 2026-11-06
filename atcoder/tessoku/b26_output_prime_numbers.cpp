#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;

  vector<int> A(n + 1);
  for (int i = 2; i <= n; i++) {
    if (A[i])
      continue;
    for (int j = i + i; j <= n; j += i)
      A[j] = 1;
  }

  for (int i = 2; i <= n; i++)
    if (!A[i])
      cout << i << "\n";
}
