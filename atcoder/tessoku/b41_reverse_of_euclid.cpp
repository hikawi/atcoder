#include <iostream>
#include <ranges>
#include <utility>
#include <vector>
using namespace std;
int main() {
  int x, y;
  cin >> x >> y;
  vector<pair<int, int>> steps;
  while (x && y) {
    steps.emplace_back(x, y);
    if (x > y) {
      x -= y;
    } else {
      y -= x;
    }
  }

  cout << steps.size() - 1 << "\n";
  for (auto &p : steps | ranges::views::reverse | ranges::views::drop(1))
    cout << p.first << " " << p.second << "\n";
}
