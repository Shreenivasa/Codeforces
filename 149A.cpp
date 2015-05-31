//149A.cpp
//Business trip
//Author: Ikki
//May 31, 2015

#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;

int a[12];

int main()
{
	int k;
	cin >> k;
	for (int i = 0; i < 12; i++)
		cin >> a[i];
	sort(a, a + 12, greater<int>());
	int sum = 0;
	if (sum >= k)
	{
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < 12; i++)
	{
		sum += a[i];
		if (sum >= k)
		{
			cout << i + 1 << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}