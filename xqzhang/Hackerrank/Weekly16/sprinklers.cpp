#include <iostream>
using namespace std;

int num[10100];

int main() {
  int T;
  cin.sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cin >> T;
  while (T--) {
    long long N, M, S, Q;
    cin >> N >> M >> S >> Q;
    long long  lastp = -1;
    long long index = 1;
    long long maxgap = -1;
    long long maxRange = -1;
    for (int i = 0; i < M; i++) {
      long long p;
      cin >> p;
      while (index < p) {
        num[index++] = lastp;
      }
      num[index++] = p;
      maxRange = max(maxRange, p - 1);
      maxRange = max(maxRange, N - p);
      if (i == 0) {
        maxgap = max(maxgap, (p - 1) * 2);
      }
      if (i == M - 1) {
        maxgap = max(maxgap, (N - p) * 2);
      }
      if (lastp != -1 && p - lastp > maxgap) {
        maxgap = p - lastp;
      }
      lastp = p;
    }
    while (index <= N) {
      num[index++] = lastp;
    }
    long long finalRange;
    long long sum = -1;
    long long counts;
    long long minRange = maxgap / 2;
    for (long long range = minRange; range <= maxRange; range++) {
      long long tempsum = range * Q;
      long long tempcounts = 0;
      int tempindex = 1;
      bool fail = false;
      while (tempindex <= N) {
        tempsum += S;
        int farest = tempindex + range;
        if (farest > N) farest = N;
        if (num[farest] + range + 1 <= tempindex) {
          fail = true;
          break;
        }
        tempindex = num[farest] + range + 1;
        tempcounts++;
      }
      if (fail) continue;
      if (sum == -1 || tempsum < sum) {
        sum = tempsum;
        finalRange = range;
        counts = tempcounts;
      }
    }
    cout << counts << " " << finalRange << endl;
    long long range = finalRange;
    int tempindex = 1;
    while (tempindex <= N) {
      int farest = tempindex + range;
      if (farest > N) farest = N;
      cout << num[farest] << " ";
      tempindex = num[farest] + range + 1;
    }
    cout << endl;
  }
}
