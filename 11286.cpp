#include <bits/stdc++.h>

using namespace std;

map<int,int> mp;

int main()
{
    int Nfrosh;
    while(scanf("%d",&Nfrosh) && Nfrosh != 0)
    {
        int Valores[Nfrosh][5];
        for(int i = 0; i < Nfrosh;i++) 
            for (int j = 0;j < 5;j++) 
            {
                int Num;
                scanf("%d",&Num);
                Valores[i][j] = Num;
                if(mp.find(Num) != mp.end())
                {
                    mp[Num] += 1;
                }
                else
                {
                    mp[Num] = 1;
                }
            }
        
    }
}
