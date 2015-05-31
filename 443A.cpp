//443A.cpp
//Anton and Letters
//Author: Ikki
//May 31, 2015

#include<iostream>
#include<string>
#include<sstream>
#include<set>
using namespace std;

int main()
{
	string str;
	getline(cin, str);
	str = str.substr(1, str.size() - 2);
	istringstream in(str);
	string token;
	set<char> s;
	while (getline(in, token, ','))
	{
		for (int i = 0; i < token.size(); i++)
			if (token[i] != ' ')
				s.insert(token[i]);
	}
	cout << s.size() << endl;
	return 0;
}