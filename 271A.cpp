//271A.cpp
//A. Beautiful Year
//Author: Ikki
//Jun 10, 2015

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n;
	cin >> n;
	bool f[10];
	while (true)
	{
		n++;
		memset(f, false, sizeof(f));
		int tmp = n;
		bool valid = true;
		while (tmp)
		{
			if (f[tmp % 10])
			{
				valid = false;
				break;
			}
			f[tmp % 10] = true;
			tmp /= 10;
		}
		if (valid)
		{
			cout << n << endl;
			return 0;
		}
	}
	return 0;
}