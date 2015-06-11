//472A.cpp
//A. Design Tutorial: Learn from Math
//Author: Ikki
//Jun 11, 2015

#include <iostream>
#include <cstring>
using namespace std;

bool isPrime[1000001];

void Sieve()
{
	memset(isPrime, true, sizeof(isPrime));
	for (int i = 2; i <= 1000000; i++)
	{
		if (isPrime[i])
		{
			for (int j = i + i; j <= 1000000; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
}

int main()
{
	Sieve();
	int n;
	cin >> n;
	for (int i = 2; i <= n-2; i++)
	{
		if (!isPrime[i] && !isPrime[n - i])
		{
			cout << i << " " << n - i << endl;
			break;
		}
	}
	return 0;
}