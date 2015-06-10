//82A.cpp
//A. Double Cola
//Author: Ikki
//Jun 10, 2015

#include <iostream>
#include <string>
using namespace std;

string names[5] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

int main()
{
	long long n;
	cin >> n;
	int cnt = 0, now = 1, sum = 0;
	while (true)
	{
		sum += now;
		if (sum >= n)
			break;
		cnt = (cnt + 1) % 5;
		if (cnt == 0)
			now *= 2;
	}
	cout << names[cnt] << endl;
	return 0;
}