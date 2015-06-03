// Author: Xiongqi ZHANG
// Problem: http://codeforces.com/contest/350/problem/C
// Submission: http://codeforces.com/contest/350/submission/11407064
// Status: AC

#include <iostream>
#include <algorithm>
using namespace std;

class Bomb {
public:
  int x, y;
  bool operator<(const Bomb& another) const {
    return abs(x) + abs(y) < abs(another.x) + abs(another.y);
  }
};

Bomb b[100000];

int main() {
  int n;
  cin.sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  int ans = 0;
  for (int i = 0; i <n; ++i) {
    cin >> b[i].x >> b[i].y;
    if (b[i].x) {
      ans += 2;
    }
    if (b[i].y) {
      ans += 2;
    }
    ans += 2;
  }
  sort(b, b + n);
  cout << ans << '\n';
  for (int i = 0; i < n; i++) {
    if (b[i].x) {
      if (b[i].x > 0) {
        cout << 1 << " " << abs(b[i].x) << " R" << '\n';
      } else {
        cout << 1 << " " << abs(b[i].x) << " L" << '\n';
      }
    }
    if (b[i].y) {
      if (b[i].y > 0) {
        cout << 1 << " " << abs(b[i].y) << " U" << '\n';
      } else {
        cout << 1 << " " << abs(b[i].y) << " D" << '\n';
      }
    }
    cout << 2 << '\n';
    if (b[i].x) {
      if (b[i].x > 0) {
        cout << 1 << " " << abs(b[i].x) << " L" << '\n';
      } else {
        cout << 1 << " " << abs(b[i].x) << " R" << '\n';
      }
    }
    if (b[i].y) {
      if (b[i].y > 0) {
        cout << 1 << " " << abs(b[i].y) << " D" << '\n';
      } else {
        cout << 1 << " " << abs(b[i].y) << " U" << '\n';
      }
    }
    cout << 3 << '\n';
  }
}
