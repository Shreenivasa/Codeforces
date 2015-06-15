// 219C.cpp
// Color Stripe
// Author: derekhh
// Jun 15, 2015

#include <iostream>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;

int f[500000][26], prevf[500000][26];

int main()
{
	string str;
	int n, nc;
	cin >> n >> nc;
	cin >> str;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < nc; j++)
			f[i][j] = INT_MAX;
	for (int i = 0; i < nc; i++) f[0][i] = 1;
	f[0][str[0] - 'A'] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < nc; j++) {
			if (j != str[i] - 'A') {
				if (f[i - 1][j] < f[i][str[i] - 'A']) {
					f[i][str[i] - 'A'] = f[i - 1][j];
					prevf[i][str[i] - 'A'] = j;
				}
			}
			else {
				for (int k = 0; k < nc; k++) {
					if (k != str[i] - 'A' && f[i - 1][j] + 1 < f[i][k]) {
						f[i][k] = f[i - 1][j] + 1;
						prevf[i][k] = j;
					}
				}
			}
		}
	}
	int ans = INT_MAX, minidx = 0;
	for (int i = 0; i < nc; i++) {
		if (f[n - 1][i] < ans) {
			ans = f[n - 1][i];
			minidx = i;
		}
	}
	cout << ans << endl;
	string ansstr = "";
	for (int i = n - 1; i >= 0; i--) {
		ansstr += (minidx + 'A');
		minidx = prevf[i][minidx];
	}
	reverse(ansstr.begin(), ansstr.end());
	cout << ansstr << endl;
	return 0;
}