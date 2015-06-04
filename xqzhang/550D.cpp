// Author: Xiongqi ZHANG
// Problem: http://codeforces.com/contest/550/problem/D
// Submission: http://codeforces.com/contest/550/submission/11435368
// Status: AC

#include <iostream>
using namespace std;

int main() {
  int k;
  cin >> k;
  if (k % 2 == 0) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  int size = k - 1;
  int v = size * 4 + 2;
  int e = v * k / 2;
  cout << v << " " << e << endl;
  cout << 1 << " " << 2 << endl;
  for (int i = 3; i < 3 + size; i++) {
    cout << 1 << " " << i << endl;
    for (int j = 3 + size; j < 3 + size + size; j++) {
      cout << i << " " << j << endl;
    }
  }
  for (int j = 3 + size; j < 3 + size + size; j += 2) {
    cout << j << " " << j + 1 << endl;
  }
  for (int i = 3 + size * 2; i < 3 + size * 3; i++) {
    cout << 2 << " " << i << endl;
    for (int j = 3 + size * 3; j < 3 + size * 4; j++) {
      cout << i << " " << j << endl;
    }
  }
  for (int j = 3 + size * 3; j < 3 + size * 4; j += 2) {
    cout << j << " " << j + 1 << endl;
  }
}
