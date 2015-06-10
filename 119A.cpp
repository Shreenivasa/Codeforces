//119A.cpp
//A. Epic Game
//Author: Ikki
//Jun 10, 2015

#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	int a[2], n;
	cin >> a[0] >> a[1] >> n;
	while (true)
	{
		for (int i = 0; i < 2; i++)
		{
			int val = gcd(n, a[i]);
			if (n >= val)
				n -= val;
			else
			{
				cout << 1 - i << endl;
				return 0;
			}
		}
	}
	return 0;
}