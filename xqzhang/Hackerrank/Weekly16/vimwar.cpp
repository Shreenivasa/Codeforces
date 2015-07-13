#include <iostream>
#include <cstring>
using namespace std;

int num[100000];
int pow2[100001];

const int MOD = 1000000007;

int fromStr(char* s) {
  int res = 0;
  while (*s) {
    res <<= 1;
    res += *s - '0';
    s++;
  }
  return res;
}

int convert(char* buf, int val, int M) {
  int temp = 1;
  int newval = 0;
  for (int i = M - 1; val && i >= 0; i--) {
    if (buf[i] == '1') {
      if (val & 1) {
        newval |= temp;
      }
      temp <<= 1;
    } else if (val & 1) {
      return -1;
    }
    val >>= 1;
  }
  return newval;
}

int countbits(int val) {
  int res = 0;
  while (val) {
    if (val & 1) res++;
    val >>= 1;
  }
  return res;
}

void adds(int& a, const int& val) {
  a = (a + val) % MOD;
}

long long dp[(1 << 20) + 1000];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  pow2[0] = 1;
  for (int i = 1; i <= 100000; i++) {
    pow2[i] = (pow2[i - 1] << 1) % MOD;
  }
  char buf[30];
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> buf;
    num[i] = fromStr(buf);
  }
  cin >> buf;
  int newM = 0;
  for (int i = 0; i < M; i++) {
    if (buf[i] == '1') newM++;
  }
  int newN = 0;
  for (int i = 0; i < N; i++) {
    int temp = convert(buf, num[i], M);
    if (temp != -1) {
      num[newN++] = temp;
    }
  }
  M = newM;
  N = newN;
  if (M == 0) {
    cout << (pow2[N] + MOD - 1) % MOD << endl;
    return 0;
  }
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < N; i++) {
    dp[num[i]]++;
  }
  int mask = 1;
  for (int i = 0; i < M; i++) {
    for (int j = (1 << M) - 1; j >= 0; j--) {
      if ((j & mask) == 0) {
        dp[j | mask] += dp[j];
      }
    }
    mask <<= 1;
  }
  int ans = 0;
  for (int i = (1 << M) - 1; i >= 0; i--) {
    int pos = 1 - ((countbits(i) + M) & 1);
    int counts = dp[i];
    if (pos) {
      adds(ans, pow2[counts]);
    } else {
      adds(ans, MOD - pow2[counts]);
    }
  }
  cout << ans << endl;
}
