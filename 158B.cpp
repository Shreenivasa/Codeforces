//158B.cpp
//B. Taxi
//Author: Ikki
//May 31, 2015

#include<iostream>
#include<algorithm>
using namespace std;

int cnt[5];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		cnt[num] ++;
	}
	int tmp = min(cnt[3], cnt[1]);
	int ans = cnt[4] + tmp + cnt[2] / 2;
	cnt[3] -= tmp;
	cnt[1] -= tmp;
	cnt[2] %= 2;
	if (cnt[3] != 0)
		ans += cnt[3] + cnt[2];
	else
	{
		ans += cnt[1] / 4;
		int rem = cnt[1] % 4 + cnt[2] * 2;
		int num = rem / 4 + (rem % 4 ? 1 : 0);
		ans += num;
	}
	cout << ans << endl;
	return 0;
}