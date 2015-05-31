//1A.cpp
//Theatre Square
//Author: derekhh
//May 31, 2015

#include<iostream>
using namespace std;

int main()
{
	int n, m, a;
	cin >> n >> m >> a;
	int w = n / a + (n % a ? 1 : 0);
	int h = m / a + (m % a ? 1 : 0);
	cout << static_cast<long long>(w)* h << endl;
	return 0;
}