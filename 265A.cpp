//265A.cpp
//Colorful Stones (Simplified Edition)
//Author: Ikki
//Jun 2, 2015

#include<iostream>
#include<string>>
using namespace std;

int main()
{
	string s, t;
	cin >> s >> t;
	int pos = 0;
	for (int i = 0; i < t.size(); i++)
		if (t[i] == s[pos])
			pos++;
	cout << pos + 1 << endl;
	return 0;
}