// 144A.cpp
// A. Arrival of the General
// Author: Ikki
// Jun 12, 2015

#include <iostream>
using namespace std;

int main()
{
	int n, minh = 101, maxh = 0;
	int a[100];
	int minidx = 0, maxidx = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] <= minh)
		{
			minh = a[i];
			minidx = i;
		}
		if (a[i] > maxh)
		{
			maxh = a[i];
			maxidx = i;
		}
	}
	cout << maxidx + n - 1 - minidx - (minidx < maxidx) << endl;
	return 0;
}