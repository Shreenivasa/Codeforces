// Author: Xiongqi ZHANG
// Problem: http://codeforces.com/problemset/problem/146/B
// Submission: http://codeforces.com/contest/146/submission/11625255
// Status: AC

#include <iostream>
using namespace std;

int mask(int a) {
  int b = 0;
  while(a) {
    if (a % 10 == 4 || a % 10 == 7) {
      b = b * 10 + a % 10;
    }
    a /= 10;
  }
  int c = 0;
  while(b) {
    c = c * 10 + b % 10;
    b /= 10;
  }
  return c;
}

int main() {
  int a, b;
  cin >> a >> b;
  while(++a) {
    if (mask(a) == b) {
      cout << a << endl;
      return 0;
    }
  }
}
