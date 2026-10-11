#include <iostream>
#include <vector>
int main() {
  using namespace std;
  int n, q;
  cin >> n;
  vector<int> A(n), atari(n + 1), hazure(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    atari[i + 1] = atari[i];
    hazure[i + 1] = hazure[i];
    if (A[i]) {
      atari[i + 1]++;
    } else {
      hazure[i + 1]++;
    }
  }

  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    int a = atari[r] - atari[l - 1], b = hazure[r] - hazure[l - 1];
    if (a == b) {
      cout << "draw\n";
    } else if (a > b) {
      cout << "win\n";
    } else {
      cout << "lose\n";
    }
  }
}
