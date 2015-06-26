// 344A.cpp
// A. Magnets
// Author: Ikki
// Jun 26, 2015

#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	string prev;
	cin >> n >> prev;
	int ans = 1;
	for (int i = 1; i < n; i++) {
		string str;
		cin >> str;
		if (str[0] == prev[1]) ans++;
		prev = str;
	}
	cout << ans << endl;
	return 0;
}