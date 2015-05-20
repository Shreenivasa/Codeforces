//354C.cpp
//Vasya and Beautiful Arrays
//Author: Ikki
//May 20, 2015

#include<iostream>
#include<set>
using namespace std;

const int MAXN = 1000000;
int a[MAXN], cnt[MAXN + 1], sum[MAXN + 1];

int main()
{
	int n, k;
	cin >> n >> k;
	int minval = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] < minval)
			minval = a[i];
		cnt[a[i]]++;
	}

	if (minval <= k + 1)
	{
		cout << minval << endl;
	}

	else
	{
		for (int i = 1; i <= MAXN; i++)
			sum[i] = sum[i - 1] + cnt[i];

		int ans = 0;

		for (int g = 2; g <= minval; g++)
		{
			//suppose the final gcd is g, now we only need to check whether a[i] mod g <= k
			//in other words we only need to check whether cnt[1..k] + cnt[g..g+k] + cnt[2*g..2*g+k] ... = n
			//sum[k] - sum[0] + sum[g+k] - sum[g-1] + ...
			int val = 0;
			for (int i = 0; i * g - 1 <= MAXN; i++)
			{
				if (k + i * g > MAXN)
					val += sum[MAXN] - sum[i * g - 1];
				else
					val += sum[k + i * g] - sum[i * g - 1];
			}
			if (val == n)
				ans = g;
		}
		cout << ans << endl;
	}
	return 0;
}