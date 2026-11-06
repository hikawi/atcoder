#include <bits/stdc++.h>
#include <ranges>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)

vector<array<bool, 5>> combinations = {
    {true, true, true, true, true},     // ABCDE
    {false, true, true, true, true},    // BCDE
    {true, false, true, true, true},    // ACDE
    {true, true, false, true, true},    // ABDE
    {true, true, true, false, true},    // ABCE
    {true, true, true, true, false},    // ABCD
    {false, false, true, true, true},   // CDE
    {false, true, false, true, true},   // BDE
    {true, false, false, true, true},   // ADE
    {false, true, true, false, true},   // BCE
    {true, false, true, false, true},   // ACE
    {false, true, true, true, false},   // BCD
    {true, true, false, false, true},   // ABE
    {true, false, true, true, false},   // ACD
    {true, true, false, true, false},   // ABD
    {true, true, true, false, false},   // ABC
    {false, false, false, true, true},  // DE
    {false, false, true, false, true},  // CE
    {false, true, false, false, true},  // BE
    {false, false, true, true, false},  // CD
    {true, false, false, false, true},  // AE
    {false, true, false, true, false},  // BD
    {true, false, false, true, false},  // AD
    {false, true, true, false, false},  // BC
    {true, false, true, false, false},  // AC
    {true, true, false, false, false},  // AB
    {false, false, false, false, true}, // E
    {false, false, false, true, false}, // D
    {false, false, true, false, false}, // C
    {false, true, false, false, false}, // B
    {true, false, false, false, false}  // A
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  array<int, 5> A;
  rep(i, 5) cin >> A[i];
  vector<pair<int, string>> participants;

  for (auto c : combinations) {
    string s = "";
    int score = 0;

    for (int i = 0; i < 5; i++) {
      if (c[i]) {
        s.push_back('A' + i);
        score += A[i];
      }
    }

    participants.emplace_back(score, s);
  }

  sort(participants.begin(), participants.end(),
       [&](const auto a, const auto b) { return a.first == b.first ? a.second > b.second : a.first < b.first; });

  for (const auto p : participants | views::reverse) {
    cout << p.second << endl;
  }

  return 0;
}
