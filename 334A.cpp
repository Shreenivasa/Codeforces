//334A.cpp
//Candy Bags
//Author: Ikki
//Jun 2, 2015

#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int p = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n / 2; j++)
		{
			cout << p << " " << n * n + 1 - p << " ";
			p++;
		}
		cout << endl;
	}
	return 0;
}