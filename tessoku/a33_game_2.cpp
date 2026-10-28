#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++)
    cin >> A[i];

  int a = A[0];
  for (int i = 1; i < n; i++)
    a ^= A[i];
  if (a == 0)
    cout << "Second\n";
  else
    cout << "First\n";
}
