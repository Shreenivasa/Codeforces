#include <iostream>
#include <cstring>
using namespace std;

int a[8000];
int b[8000];
int axorb[8000];

int ans[8001];

int parent[64];

int find_parent(int i) {
  if (parent[i] != i) {
    parent[i] = find_parent(parent[i]);
  }
  return parent[i];
}

bool merge(int a, int b) {
  int pa = find_parent(a);
  int pb = find_parent(b);
  if (pa == pb) {
    return false;
  }
  parent[pa] = pb;
  return true;
}

int pow2[8001];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int N, M;
  cin >> N >> M;
  pow2[0] = 1 % M ;
  for (int i = 1; i <= 8000; i++) {
    pow2[i] = (pow2[i - 1] << 1) % M;
  }
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> b[i];
    axorb[i] = a[i] ^ b[i];
  }
  memset(ans, 0, sizeof(ans));
  for (int L = 0; L < N; L++) {
    for (int i = 0; i < 64; i++) {
      parent[i] = i;
    }
    int size = 0;
    bool hasmask[64];
    memset(hasmask, 0, sizeof(hasmask));
    hasmask[0] = true;
    int temp = 0;
    for (int R = L; R < N; R++) {
      if (merge(a[R], b[R])) {
        size++;
        for (int i = 0; i < 64; i++) {
          merge(i, i ^ axorb[R]);
          if (!hasmask[i]) continue;
          hasmask[i ^ axorb[R]] = true;
        }
      }
      temp ^= a[R];
      if (hasmask[temp]) {
        ans[R - L + 1] += pow2[R - L + 1 - size];
        ans[R - L + 1] %= M;
      }
    }
  }
  for (int i = 1; i <= N; i++) {
    cout << ans[i] << endl;
  }
}
