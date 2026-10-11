#include <iostream>
#include <vector>
int main() {
  using namespace std;
  int d, n;
  cin >> d >> n;

  vector<int> A(d + 1);
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    A[l]++;
    A[r + 1]--;
  }

  int s = 0;
  for (int i = 1; i <= d; i++) {
    s += A[i];
    cout << s << "\n";
  }
}
