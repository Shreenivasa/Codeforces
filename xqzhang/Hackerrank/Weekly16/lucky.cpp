#include <iostream>
using namespace std;

long long dp[110][110][110];
long long counts[110][110][110];

const int MOD = 1000000007;

void adds(long long& a, long long add) {
  a = (a + add) % MOD;
}

long long tens[400];

int main() {
  int x, y, z;
  cin >> x >> y >> z;
  dp[0][0][0] = 0;
  counts[0][0][0] = 1;
  tens[0] = 1;
  for (int i = 1; i < 400; i++) {
    tens[i] = tens[i-1] * 10 % MOD;
  }
  long long ans = 0;
  for (int i = 0; i <= x; i++) {
    for (int j = 0; j <= y; j++) {
      for (int k = 0; k <= z; k++) {
        if (i == 0 && j == 0 && k == 0) continue;
        long long& temp = tens[i + j + k - 1];
        counts[i][j][k] = dp[i][j][k] = 0;
        if (i > 0) {
          adds(counts[i][j][k], counts[i-1][j][k]);
          adds(dp[i][j][k], 4 * temp % MOD * counts[i-1][j][k] + dp[i-1][j][k]);
        }
        if (j > 0) {
          adds(counts[i][j][k], counts[i][j-1][k]);
          adds(dp[i][j][k], 5 * temp % MOD * counts[i][j-1][k] + dp[i][j-1][k]);
        }
        if (k > 0) {
          adds(counts[i][j][k], counts[i][j][k-1]);
          adds(dp[i][j][k], 6 * temp % MOD * counts[i][j][k-1] + dp[i][j][k-1]);
        }
        adds(ans, dp[i][j][k]);
      }
    }
  }
  cout << ans << endl;
}
