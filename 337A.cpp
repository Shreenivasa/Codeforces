// 337A.cpp
// A. Puzzles
// Author: Ikki
// Jun 26, 2015

#include <iostream>
#include <algorithm>
using namespace std;

int f[50];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> f[i];
	sort(f, f + m);
	int ans = INT_MAX;
	for (int i = n - 1; i < m; i++)
		ans = min(ans, f[i] - f[i - n + 1]);
	cout << ans << endl;
	return 0;
}