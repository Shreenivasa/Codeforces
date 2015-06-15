// 451A.cpp
// A. Game With Sticks
// Author: Ikki
// Jun 12, 2015

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	if (min(n, m) % 2 == 0)
		cout << "Malvika" << endl;
	else
		cout << "Akshat" << endl;
	return 0;
}