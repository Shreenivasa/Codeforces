//118D.cpp
//D. Caesar's Legions
//Author: Ikki
//Jun 11, 2015

#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 100000000;

int f[101][101][11][2];

void add(int& a, int b)
{
    a = (a + b) % MOD;
}

int main()
{
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    memset(f, 0, sizeof(f));
    f[1][0][1][0] = 1;
    f[0][1][1][1] = 1;

    for (int i = 0; i <= n1; i++)
    {
        for (int j = 0; j <= n2; j++)
        {
            if (i == 0 && j == 0) continue;
            for (int k = 1; k <= 10; k++)
            {
                for(int l = 0; l < 2; l++)
                {
                    if (f[i][j][k][l] != 0)
                    {
                        if (l == 0)
                        {
                            if (i != n1 && k != k1)
                                add(f[i + 1][j][k + 1][l], f[i][j][k][l]);
                            if (j != n2)
                                add(f[i][j + 1][1][1], f[i][j][k][l]);
                        }
                        else
                        {
                            if (j != n2 && k != k2)
                                add(f[i][j + 1][k + 1][l], f[i][j][k][l]);
                            if (i != n1)
                                add(f[i + 1][j][1][0], f[i][j][k][l]);
                        }
                    }
                }
            }
        }
    }

    int sum = 0;
    for (int i = 1; i <= 10; i++)
    {
        if (i <= k1)
            add(sum, f[n1][n2][i][0]);
        if (i <= k2)
            add(sum, f[n1][n2][i][1]);
    }
    cout << sum << endl;
    return 0;
}