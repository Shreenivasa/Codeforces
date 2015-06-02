//499B.cpp
//Lecture
//Author: Ikki
//May 31, 2015

#include<iostream>
#include<string>
#include<map>
using namespace std;

map<string, string> ma;

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		string a, b;
		cin >> a >> b;
		ma[a] = b;
	}
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		if (ma[str].size() < str.size())
			cout << ma[str] << " ";
		else
			cout << str << " ";
	}
	cout << endl;
	return 0;
}