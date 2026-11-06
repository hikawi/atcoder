#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main() {
  int q;
  cin >> q;
  unordered_map<string, int> M;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      string s;
      int n;
      cin >> s >> n;
      M[s] = n;
    } else {
      string s;
      cin >> s;
      cout << M[s] << "\n";
    }
  }
}
