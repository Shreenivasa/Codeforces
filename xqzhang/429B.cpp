// Author: Xiongqi ZHANG
// Problem: http://codeforces.com/contest/429/problem/B
// Submission: http://codeforces.com/contest/429/submission/11394781
// Status: AC

#include <iostream>
#include <cstring>
using namespace std;

int dp[4][1001][1001];
int data[1001][1001];

int main() {
  int n, m;
  cin >> n >> m;
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> data[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int& value = dp[0][i][j];
      value = data[i][j];
      int extra = 0;
      if (i > 0) {
        extra = max(extra, dp[0][i-1][j]);
      }
      if (j > 0) {
        extra = max(extra, dp[0][i][j-1]);
      }
      value += extra;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = m - 1; j >= 0; j--) {
      int& value = dp[1][i][j];
      value = data[i][j];
      int extra = 0;
      if (i > 0) {
        extra = max(extra, dp[1][i-1][j]);
      }
      if (j < m - 1) {
        extra = max(extra, dp[1][i][j+1]);
      }
      value += extra;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < m; j++) {
      int& value = dp[2][i][j];
      value = data[i][j];
      int extra = 0;
      if (i < n - 1) {
        extra = max(extra, dp[2][i+1][j]);
      }
      if (j > 0) {
        extra = max(extra, dp[2][i][j-1]);
      }
      value += extra;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      int& value = dp[3][i][j];
      value = data[i][j];
      int extra = 0;
      if (i < n - 1) {
        extra = max(extra, dp[3][i+1][j]);
      }
      if (j < m - 1) {
        extra = max(extra, dp[3][i][j+1]);
      }
      value += extra;
    }
  }
  int maxvalue = 0;
  int ansi, ansj;
  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < m - 1; j++) {
      int temp = 0;
      temp += dp[0][i - 1][j];
      temp += dp[3][i + 1][j];
      temp += dp[2][i][j - 1];
      temp += dp[1][i][j + 1];
      maxvalue = max(maxvalue, temp);
      temp = 0;
      temp += dp[1][i - 1][j];
      temp += dp[2][i + 1][j];
      temp += dp[0][i][j - 1];
      temp += dp[3][i][j + 1];
      maxvalue = max(maxvalue, temp);
    }
  }
  //cerr << ansi << " " << ansj << endl;
  cout << maxvalue << endl;
}
