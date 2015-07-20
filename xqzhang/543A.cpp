// Author: Xiongqi ZHANG
// Problem: http://codeforces.com/contest/543/problem/A
// Submission: http://codeforces.com/contest/543/submission/12136507
// Status: AC

#include <iostream>
#include <cstring>
using namespace std;

int dp[501][501];

int main() {
  int n, m, b, mod;
  cin >> n >> m >> b >> mod;
  int a[501];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int t = 1; t <= n; t++) {
    for (int i = 1; i <= m; i++) {
      for (int j = a[t]; j <= b; j++) {
        dp[i][j] += dp[i-1][j - a[t]];
        dp[i][j] %= mod;
      }
    }
  }
  int sum = 0;
  for (int i = 0; i <= b; i++) {
    sum += dp[m][i];
    sum %= mod;
  }
  cout << sum << endl;
}
