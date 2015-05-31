//136A.cpp
//Presents
//Author: Ikki
//May 31, 2015

#include<iostream>
using namespace std;

int val[101];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		val[num] = i + 1;
	}
	for (int i = 1; i <= n; i++)
		cout << val[i] << " ";
	cout << endl;
	return 0;
}