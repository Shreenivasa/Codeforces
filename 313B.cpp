//313B.cpp
//Ilya and Queries
//Author: Ikki
//May 31, 2015

#include<cstdio>
using namespace std;

char str[100000];
int sum[100000];

int main()
{
	gets(str);
	for (int i = 1; str[i] != '\0'; i++)
		sum[i] = sum[i - 1] + (str[i] == str[i - 1]);
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", sum[b - 1] - sum[a - 1]);
	}
	return 0;
}