//122A.cpp
//A. Lucky Division
//Author: Ikki
//Jun 10, 2015

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> divisors {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};
	int n;
	cin >> n;
	for(auto val : divisors)
	{
		if (n % val == 0)
		{
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}