//131A.cpp
//cAPS lOCK
//Author: Ikki
//May 31, 2015

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	cin >> str;
	bool shouldChange = true;
	for (int i = 1; i < str.size(); i++)
		if (!isupper(str[i]))
			shouldChange = false;
	if (shouldChange)
	{
		for (int i = 0; i < str.size(); i++)
		{
			char ch;
			if (islower(str[i]))
				ch = toupper(str[i]);
			else
				ch = tolower(str[i]);
			cout << ch;
		}
		cout << endl;
	}
	else
	{
		cout << str << endl;
	}
	return 0;
}