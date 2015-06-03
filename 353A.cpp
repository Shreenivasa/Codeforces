//353A.cpp
//Domino
//Author: Ikki
//Jun 2, 2015

#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int s1 = 0, s2 = 0;
	bool f = false;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		if ((x & 1) != (y & 1)) f = true;
		s1 += x;
		s2 += y;
	}
	int f1 = s1 & 1, f2 = s2 & 1;
	if (f1 + f2 == 0)
		cout << 0 << endl;
	else if (f1 + f2 == 2)
		cout << (f ? 1 : -1) << endl;
	else
		cout << -1 << endl;
	return 0;
}