//285C.cpp
//Building Permutation
//Author: Ikki
//Jun 2, 2015

#include<iostream>
#include<algorithm>
using namespace std;

int a[300000];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	long long ans = 0;
	for (int i = 0; i < n; i++)
		ans += abs(i + 1 - a[i]);
	cout << ans << endl;
	return 0;
}