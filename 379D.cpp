//379D.cpp
//New Year Letter
//Author: Ikki
//May 19, 2015

#include<iostream>
using namespace std;

pair<long long, int> f[51];

int foo(int len, int state)
{
	if (state == 0) return len / 2;

	if (len % 2 == 0)
	{
		if (state != 0) return len / 2 - 1;
		return len / 2;
	}

	else
	{
		if (state != 3) return len / 2;
		return len / 2 - 1;
	}
}

void foo2(int len, int numAC, int state)
{
	int cnt = 0;
	if (state & 2)
	{
		cout << "C"; cnt++;
	}
	for (int t = 0; t < numAC; t++, cnt += 2)
		cout << "AC";
	for (int i = 0; i < len - cnt - (state & 1 ? 1 : 0); i++)
		cout << "B";
	if (state & 1)
		cout << "A";
	cout << endl;
}

int main()
{
	int k, x, n, m;
	cin >> k >> x >> n >> m;
	for (int s1 = 0; s1 < 4; s1++)
	{
		for (int s2 = 0; s2 < 4; s2++)
		{
			for (int i = 0; i <= foo(n, s1); i++)
			{
				for (int j = 0; j <= foo(m, s2); j++)
				{
					memset(f, 0, sizeof(f));
					f[1] = pair<long long, int>(i, s1);
					f[2] = pair<long long, int>(j, s2);
					for (int ii = 3; ii <= k; ii++)
					{
						int val1 = f[ii - 2].second & 1; //ends with A
						int val2 = f[ii - 1].second & 2; //starts with C
						long long newval = f[ii - 2].first + f[ii - 1].first;
						if (newval > x) newval = x + 1;
						if (val1 && val2) newval++;
						f[ii].first = newval;
						f[ii].second = ((f[ii - 1].second & 1) | (f[ii - 2].second & 2));
					}

					if (f[k].first == x)
					{
						foo2(n, i, s1);
						foo2(m, j, s2);
						return 0;
					}
				}
			}
		}
	}
	cout << "Happy new year!" << endl;
	return 0;
}