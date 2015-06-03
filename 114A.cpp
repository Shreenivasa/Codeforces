//114A.cpp
//Cifera
//Author: Ikki
//Jun 2, 2015

#include<iostream>
using namespace std;

int main()
{
	long long k, l;
	cin >> k >> l;
	long long tmp = k;
	int cnt = 0;
	while (tmp < l)
	{
		tmp *= k;
		cnt++;
	}
	if (tmp == l)
		cout << "YES" << endl << cnt << endl;
	else
		cout << "NO" << endl;
	return 0;
}