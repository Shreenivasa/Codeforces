// 486A.cpp
// A. Calculating Function
// Author: Ikki
// Jun 26, 2015

#include <iostream>
using namespace std;

int main() {
	long long n;
	cin >> n;
	if (n % 2 == 0)
		cout << n / 2 << endl;
	else
		cout << - (n + 1) / 2 << endl;
	return 0;
}