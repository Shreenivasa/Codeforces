//379A.cpp
//New Year Candles
//Author: Ikki
//Jun 11, 2015

#include <iostream>
using namespace std;

int main()
{
	int a, b, sum = 0, rem = 0;
	cin >> a >> b;
	sum = a, rem = a;
	while (rem >= b)
	{
		sum += rem / b;
		rem = rem / b + rem % b;
	}
	cout << sum << endl;
	return 0;
}