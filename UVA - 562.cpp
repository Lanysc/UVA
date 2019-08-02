#include <bits/stdc++.h>

using namespace std;

typedef long long ii;

ii n, memo[50000][100];
ii V[1000];

ii bag(ii i, ii disp)
{
    if(i == n || disp == 0) return 0;

    ii &pd = memo[i][disp];

    if (pd != -1) return pd;

    if (V[i] > disp)
        return pd = bag(i+1,disp);
    return pd = max(bag(i+1,disp), V[i]+bag(i+1,disp-V[i]));
}

int main()
{
    ii w, sum, valor, cases;
    scanf("%lld",&cases);
    while(cases--)
    {
		cin >> n;
		valor = 0;
        for (int i = 0;i < n;i ++)
        {
            cin >> V[i];
            valor += V[i];
        }
        memset(memo,-1,sizeof memo);
		    w = valor / 2;
        sum = bag(0,w);
        printf("%lld\n",valor - sum*2);
    }

}
