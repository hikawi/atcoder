#include <bits/stdc++.h>
using namespace std;

void insert_sorted(std::vector<int> &vec, int value) {
  auto it = lower_bound(vec.begin(), vec.end(), value);
  vec.insert(it, value);
}

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> *boxes = new vector<int>[n];
  unordered_map<int, set<int>> refs;

  for (int a = 0; a < q; a++) {
    int ins, i, j;
    cin >> ins;
    switch (ins) {
    case 1:
      cin >> i >> j;
      insert_sorted(boxes[j - 1], i);
      refs[i].insert(j);
      break;
    case 2:
      cin >> i;
      for (int x = 0; x < boxes[i - 1].size(); x++) {
        cout << boxes[i - 1][x];
        if (x < boxes[i - 1].size() - 1)
          cout << " ";
      }
      cout << endl;
      break;
    case 3:
      cin >> i;
      bool first = true;
      for (const auto &val : refs[i]) {
        if (!first)
          cout << " ";
        cout << val;
        first = false;
      }
      cout << endl;
      break;
    }
  }
}
