// 553A.cpp
// A. Kyoya and Colored Balls
// Author: Ikki
// Jun 26, 2015

#include <iostream>
using namespace std;

int f[1000], c[1000];
int comb[1001][1001];
const int MOD = 1000000007;

int main() {
	int k;
	cin >> k;
	for (int i = 1; i <= 1000; i++)
		comb[i][0] = comb[i][i] = 1;
	for (int i = 2; i <= 1000; i++)
		for (int j = 1; j <= 1000; j++)
				comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
	for (int i = 0; i < k; i++)
		cin >> c[i];
	f[0] = 1;
	int sum = c[0];
	for (int i = 1; i < k; i++) {
		sum += c[i];
		f[i] = ((long long) f[i - 1] * comb[sum - 1][c[i] - 1]) % MOD;
	}
	cout << f[k - 1] << endl;
	return 0;
}