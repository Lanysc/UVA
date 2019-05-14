#include <bits/stdc++.h>

using namespace std;

int main()
{
    int long long num, matrix[4][8], cont = 0, NumA, soma,sinal, pot;
    while(scanf("%lld",&num) == 1)
    {
		sinal = 1;
		soma = 0;
		NumA = num;
		cont = 0;
		pot = 1;
		if (num < 0)
		{
			sinal = -1;
			num = abs(num);
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (num / 2 != 0 || num == 1)
				{
					matrix[i][j] = num % 2;
					num = num / 2;
				}
				else
				{
					matrix[i][j] = 0;
				}
				cout << matrix[i][j];
			}
			puts ("");
		}
		puts ("");
		for (int i = 3; i >= 0; i--)
		{
			for (int j = 0; j < 8; j++,cont++)
			{
				cout << matrix[i][j];
				if (matrix[i][j] != 0)
				{
					soma += pot;
				}
				pot = pot * 2;
			}
			puts("");
		}

		printf("%lld converts to %lld\n",NumA,soma * sinal);
	}
}
