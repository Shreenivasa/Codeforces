//152A.cpp
//Marks
//Author: Ikki
//Feb 20, 2012

#include<stdio.h>

char score[110][110];
bool good[110];

int main() 
{
	int n, m;
	scanf("%d%d", &n, &m);
	getchar();
	for (int i = 0; i < n; i++)
		gets(score[i]);
	for (int i = 0; i < m; i++) {
		int best = -1;
		for (int j = 0; j<n; j++)
			if (score[j][i] - '0'>best)
				best = score[j][i] - '0';
		for (int j = 0; j < n; j++)
			if (score[j][i] - '0' == best)
				good[j] = true;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (good[i])
			cnt++;
	printf("%d\n", cnt);
	return 0;
}