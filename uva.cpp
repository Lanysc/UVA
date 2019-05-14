#include <bits/stdc++.h>

using namespace std;

int main()
{
    int long long num, matrix[4][8], cont = 0, aux = 1, conv = 1, NumA;
    scanf("%lld",&num);
    NumA = num;
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
        }

    }
    for (int i = 3; i >= 0; i--)
    {
        for (int j = 0; j < 8; j++,cont++)
        {
            if (matrix[i][j] != 0)
            {
                for (int k = aux; k <= cont; k++)
                {
                    conv = conv * 2;
                }
                aux = cont;

            }
        }

    }

    printf("%lld converts to %lld",NumA,conv);

}
