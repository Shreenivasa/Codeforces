//467A.cpp
//A. George and Accommodation
//Author: Ikki
//Jun 10, 2015

#include <iostream>
using namespace std;

int main()
{
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int p, q;
		cin >> p >> q;
		if (q - p >= 2)
			ans++;
	}
	cout << ans << endl;
	return 0;
}