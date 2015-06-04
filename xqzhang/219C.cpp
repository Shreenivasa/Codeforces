// Author: Xiongqi ZHANG
// Problem: http://codeforces.com/problemset/problem/219/C
// Submission: http://codeforces.com/contest/219/submission/11437741
// Status: AC

#include <iostream>
#include <string>
using namespace std;

int dp[2][2];

int main() {
  int n, k;
  cin >> n >> k;
  string cells;
  cin >> cells;
  if (k > 2) {
    int ans = 0;
    for (int i = 1; i < n; i++) {
      if (cells[i] == cells[i-1]) {
        ans++;
        for (int j = 0; j < 3; j++) {
          char temp = j + 'A';
          if (temp != cells[i-1] && (i == n - 1 || temp != cells[i+1])) {
            cells[i] = temp;
            break;
          }
        }
      }
    }
    cout << ans << endl << cells << endl;
  } else {
    dp[0][0] = cells[n-1] == 'B';
    dp[0][1] = cells[n-1] == 'A';
    int index = 1;
    for (int i = n - 2; i >= 0; i--, index = 1 - index) {
      if (cells[i] == 'A') {
        dp[index][0] = dp[1-index][1];
        dp[index][1] = dp[1-index][0] + 1;
      } else {
        dp[index][0] = dp[1-index][1] + 1;
        dp[index][1] = dp[1-index][0];
      }
    }
    index = 1 - index;
    cout << min(dp[index][0], dp[index][1]) << endl;
    if (dp[index][0] < dp[index][1]) {
      for (int i = 0; i < n; i++) {
        cout << char('A' + i % 2);
      }
    } else {
      for (int i = 0; i < n; i++) {
        cout << char('B' - i % 2);
      }
    }
    cout << endl;
  }
}
