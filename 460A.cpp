//460A.cpp
//Vasya and Socks
//Author: Ikki
//Jun 11, 2015

#include <iostream>
using namespace std;

int main()
{
	int n, m, sum, rem;
	cin >> n >> m;
	sum = n, rem = n;
	while (rem >= m)
	{
		sum += rem / m;
		rem = rem / m + rem % m;
	}
	cout << sum << endl;
	return 0;
}