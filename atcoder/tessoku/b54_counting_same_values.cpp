#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
  int n;
  cin >> n;
  unordered_map<long long, long long> M;
  while (n--) {
    long long a;
    cin >> a;
    M[a]++;
  }

  long long ans = 0;
  for (auto &[k, v] : M) {
    if (v > 1)
      ans += (v * (v - 1)) / 2;
  }
  cout << ans << endl;
}
