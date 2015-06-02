#include <iostream>
#include <cstring>
using namespace std;

int dp[101][101][2][11];

int main() {
  int n1, n2, K[2];
  cin >> n1 >> n2 >> K[0] >> K[1];
  memset(dp, 0, sizeof(dp));
  dp[0][0][0][0] = dp[0][0][1][0] = 1;
  for (int i = 0; i <= n1; i++) {
    for (int j = 0; j <= n2; j++) {
      if (i == 0 && j == 0) continue;
      for (int k = 0; k < 2; k++) {
        for (int l = 1; l <= K[k]; l++) {
          if (k == 0 && l > i || k == 1 && l > j) break;
          dp[i][j][k][l] = 0;
          if (l == 1) {
            for (int m = 0; m <= K[1-k]; m++) {
              if (k == 0) {
                if (m > j) break;
                dp[i][j][k][l] += dp[i-1][j][1-k][m];
              } else {
                if (m > i) break;
                dp[i][j][k][l] += dp[i][j-1][1-k][m];
              }
              dp[i][j][k][l] %= 100000000;
            }
          } else {
            if (k == 0) {
              dp[i][j][k][l] += dp[i-1][j][k][l-1];
            } else {
              dp[i][j][k][l] += dp[i][j-1][k][l-1];
            }
            dp[i][j][k][l] %= 100000000;
          }
        }
      }
    }
  }
  long long sum = 0;
  for (int k = 0; k < 2; k++) {
    for (int l = 0; l <= K[k]; l++) {
      sum += dp[n1][n2][k][l];
      sum %= 100000000;
    }
  }
  cout << sum << endl;
}
