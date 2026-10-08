#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  array<array<int, 9>, 9> sudoku;
  rep(i, 9) {
    rep(j, 9) {
      cin >> sudoku[i][j];
      sudoku[i][j]--;
    }
  }

  // check rows
  rep(i, 9) {
    array<int, 9> row{};
    rep(j, 9) {
      if (row[sudoku[i][j]]) {
        cout << "No\n";
        return 0;
      }

      row[sudoku[i][j]]++;
    }
  }

  // check cols
  rep(j, 9) {
    array<int, 9> col{};
    rep(i, 9) {
      if (col[sudoku[i][j]]) {
        cout << "No\n";
        return 0;
      }

      col[sudoku[i][j]]++;
    }
  }

  // check boxes
  for (int ys = 0; ys < 9; ys += 3) {
    for (int xs = 0; xs < 9; xs += 3) {
      array<int, 9> box{};
      for (int dy = 0; dy < 3; dy++) {
        for (int dx = 0; dx < 3; dx++) {
          int num = sudoku[ys + dy][xs + dx];
          if (box[num]) {
            cout << "No\n";
            return 0;
          }

          box[num]++;
        }
      }
    }
  }

  cout << "Yes\n";
  return 0;
}
