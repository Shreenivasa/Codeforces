//379B.cpp
//New Year Present
//Author: Ikki
//May 31, 2015

#include<iostream>
using namespace std;

int a[300];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n;i++)
	{
		for (int j = 0; j < a[i]; j++)
		{
			if (i != 0)
				cout << "LRP";
			else
				cout << "RLP";
		}
		if (i != n - 1)
			cout << "R";
	}
	cout << endl;
	return 0;
}