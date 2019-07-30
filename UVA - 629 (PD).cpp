#include <bits/stdc++.h>

using namespace std;

int n, memo[2500][2500];
int P[2500], V[2500];



int bag(int i, int disp)
{
    if(i == n || disp == 0) return 0;

    int &pd = memo[i][disp];

    if (pd != -1) return pd;

    if (P[i] > disp)
        return pd = bag(i+1,disp);
    return pd = max(bag(i+1,disp), V[i]+bag(i+1,disp-P[i]));
}

void rec (int i, int w)
{
    if (i == n || !w) return;
    if (P[i] > w) return rec(i+1,w);
    int PD = memo[i][w];
    if(PD == bag(i+1,w))
        return rec(i+1,w);
    cout << V[i] << " ";
    rec(i+1,w-P[i]);

}

int main()
{
    int w, sum;
    while(cin >> w >> n)
    {
        for (int i = 0;i < n;i ++)
        {
            cin >> P[i];
            V[i] = P[i];
        }
        memset(memo,-1,sizeof memo);

        sum = bag(0,w);
        rec(0,w);
        cout << "sum:" << sum << endl;
    }

}
