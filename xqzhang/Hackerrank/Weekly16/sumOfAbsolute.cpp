#include <iostream>
#include <algorithm>
using namespace std;

int num[100010];

int main() {
  int N, Q;
  cin >> N >> Q;
  num[0] = 0;
  for (int i = 0; i < N; i++) {
    int temp;
    cin >> temp;
    num[i + 1] = num[i] + temp;
  }
  while(Q--) {
    int L, R;
    cin >> L >> R;
    if (L > R) swap(L, R);
    int ans = abs(num[R] - num[L - 1]);
    if (ans % 2) {
      cout << "Odd" << endl;
    } else {
      cout << "Even" << endl;
    }
  }
}
