//228A.cpp
//A. Is your horseshoe on the other hoof?
//Author: Ikki
//Jun 12, 2015

#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> s;
	for (int i = 0; i < 4; i++)
	{
		int val;
		cin >> val;
		s.insert(val);
	}
	cout << 4 - s.size() << endl;
	return 0;
}