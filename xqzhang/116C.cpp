// Author: Xiongqi ZHANG
// Problem: http://codeforces.com/problemset/problem/166/C
// Submission: http://codeforces.com/contest/166/submission/11437820
// Status: AC

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  int old_n = n;
  int num[511];
  for (int i = 0; i < n; i++) {
    cin >> num[i];
  }
  sort(num, num + n);
  int smallindex = -1, largeindex;
  for (int i = 0; i < n; i++) {
    if (num[i] == x) {
      if (smallindex == -1) {
        smallindex = i;
      }
      largeindex = i;
    }
  }
  if (smallindex == -1) {
    num[n] = x;
    n++;
    sort(num, num + n);
    for (int i = 0; i < n; i++) {
      if (num[i] == x) {
        if (smallindex == -1) {
          smallindex = i;
        }
        largeindex = i;
      }
    }
  }
  int medianloc = (n + 1) / 2 - 1;
  if (medianloc <= largeindex && medianloc >= smallindex) {
    cout << n - old_n << endl;
  } else if (medianloc > largeindex) {
    for (int i = 1;;i++) {
      if ((i + n + 1) / 2 == largeindex + i + 1) {
        cout << i + n - old_n << endl;
        return 0;
      }
    }
  } else {
    for (int i = 1;;i++) {
      if ((i + n + 1) / 2 == smallindex + 1) {
        cout << i + n - old_n << endl;
        return 0;
      }
    }
  }
}
