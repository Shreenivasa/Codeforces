//339C.cpp
//C. Xenia and Weights
//Author: Ikki
//Jun 10, 2015

#include <iostream>
#include <string>
using namespace std;

struct Type
{
	int num, diff, prev, prevnode, curr;
};

//visited[i][j][k]
//i - The number of weights that have been put on the scalepans.
//j - The difference between the number of weights on LHS and RHS, plus ten.
//k - The previous weight of the scale.
bool visited[1001][20][11];
Type Q[300000];
bool flag[11];

int main()
{
	string str;
	cin >> str;
	for (int i = 1; i <= 10; i++)
		if (str[i - 1] == '1')
			flag[i] = true;
	int m;
	cin >> m;
	Type t;
	t.num = t.prev = 0;
	t.diff = 10;
	visited[0][10][0] = true;
	int head = 0, tail = 0;
	Q[tail++] = t;
	bool can = false;
	while (head < tail)
	{
		Type tmp = Q[head++];
		for (int i = 1; i <= 10; i++)
		{
			if (flag[i] && i != tmp.prev)
			{
				Type next;
				next.num = tmp.num + 1;
				next.diff = (tmp.num % 2 == 0 ? tmp.diff + i : tmp.diff - i);
				next.prev = i;
				next.prevnode = head - 1;
				next.curr = i;

				int prevdiff = tmp.diff - 10;
				int nextdiff = next.diff - 10;
				if ((prevdiff < 0 && nextdiff > 0) || (prevdiff > 0 && nextdiff < 0) || (prevdiff == 0))
				{
					if (next.diff >= 0 && next.diff <= 20 && !visited[next.num][next.diff][next.prev])
					{
						visited[next.num][next.diff][next.prev] = true;
						Q[tail++] = next;
					
						if (next.num == m)
						{
							can = true;
							break;
						}
					}
				}
			}
		}

		if (can)
			break;
	}

	if (can)
	{
		cout << "YES" << endl;
		int ans[1000], nans = 0;
		int now = tail - 1;
		while (now != 0)
		{
			ans[nans++] = Q[now].curr;
			now = Q[now].prevnode;
		}
		for (int i = nans - 1; i >= 0; i--)
			cout << ans[i] << " ";
		cout << endl;
	}
	else
		cout << "NO" << endl;
	return 0;
}