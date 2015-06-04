// Author: Xiongqi ZHANG
// Problem: http://codeforces.com/problemset/problem/518/D
// Submission: http://codeforces.com/contest/518/submission/11415020
// Status: AC

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

typedef long double ld;

ld C(int n, int i) {
  if (n - i < i) {
    i = n - i;
  }
  ld ans = 1;
  for (int j = 1; j <= i; j++) {
    ans *= n - j + 1;
    ans /= j;
  }
  return ans;
}

int main() {
  int n, t;
  ld p;
  cin >> n >> p >> t;
  if (p == 1) {
    cout << n << endl;
    return 0;
  }
  ld sum = 0;
  ld temp = pow(1 - p, t);
  //cout << temp << endl;
  for (int i = 1; i <= t; i++) {
    temp = temp * p / (1 - p);
    temp *= (t - i + 1.0) / i;
    sum += min(i, n) * temp;
  }
  cout << fixed << setprecision(10) << sum << endl;
}
