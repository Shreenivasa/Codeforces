//61A.cpp
//Ultra-Fast Mathematician
//Author: Ikki
//May 31, 2015

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;
	for (int i = 0; i < a.size(); i++)
		if (a[i] != b[i])
			cout << 1;
		else
			cout << 0;
	cout << endl;
	return 0;
}