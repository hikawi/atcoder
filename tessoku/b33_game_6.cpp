#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, h, w;
  cin >> n >> h >> w;
  vector<int> A(n), B(n);
  for (int i = 0; i < n; i++)
    cin >> A[i] >> B[i];

  int x = A[0] - 1;
  for (int i = 1; i < n; i++)
    x ^= A[i] - 1;
  for (int i = 0; i < n; i++)
    x ^= B[i] - 1;

  if (x)
    cout << "First\n";
  else
    cout << "Second\n";
}
