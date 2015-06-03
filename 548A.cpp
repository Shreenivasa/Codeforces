//548A.cpp
//Mike and Fax
//Author: Ikki
//Jun 2, 2015

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int k;
	cin >> k;
	if (s.size() % k != 0)
	{
		cout << "NO" << endl;
		return 0;
	}
	for (int i = 0; i < s.size(); i += s.size() / k)
	{
		string ss = s.substr(i, s.size() / k);
		for (int j = 0, l = ss.size() - 1; j < l; j++, l--)
		{
			if (ss[j] != ss[l])
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	return 0;
}