//322A.cpp
//Ciel and Dancing
//Author: Ikki
//Jun 2, 2015

#include<iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	cout << n + m - 1 << endl;
	for (int i = 1; i <= m; i++)
		cout << 1 << " " << i << endl;
	for (int i = 2; i <= n; i++)
		cout << i << " " << m << endl;
	return 0;
}