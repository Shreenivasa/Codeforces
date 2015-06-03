//129A.cpp
//Cookies
//Author: Ikki
//Jun 2, 2015

#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int sum = 0, e = 0, o = 0;
	for (int i = 0; i < n;i++)
	{
		int val;
		cin >> val;
		sum ^= val;
		if (val & 1) o++;
		else e++;
	}
	if (sum & 1)
		cout << o << endl;
	else
		cout << e << endl;
	return 0;
}