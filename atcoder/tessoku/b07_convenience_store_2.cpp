#include <iostream>
#include <vector>
int main() {
  using namespace std;
  int t, n;
  cin >> t >> n;
  vector<int> T(t + 1);
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    T[l]++;
    T[r]--;
  }

  int s = 0;
  for (int i = 0; i < t; i++) {
    s += T[i];
    cout << s << "\n";
  }
}
