//112A.cpp
//Petya and Strings
//Author: Ikki
//Jun 2, 2015

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;
	transform(a.begin(), a.end(), a.begin(), tolower);
	transform(b.begin(), b.end(), b.begin(), tolower);
	if (a < b)
		cout << -1 << endl;
	else if (a == b)
		cout << 0 << endl;
	else
		cout << 1 << endl;
	return 0;
}