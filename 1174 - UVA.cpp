#include <bits/stdc++.h>

using namespace std;

typedef vector<unsigned int> vt;
typedef pair<int,int> ii;

vt P(10000,0);
vt qtd(10000,1);
vector<pair<int,ii>> EdgeList;

unsigned int Find(unsigned int u)
{
    if (u == P[u])
        return u;
    return Find(P[u]);
}

void unionSet(unsigned int a,unsigned int b)
{
    a = Find(a);
    b = Find(b);
    if (qtd[a] > qtd[b])
    {
        P[b] = a;
        qtd[a] += qtd[b];
    }
    else
    {
        P[a] = b;
        qtd[b] += qtd[a];
    }
}

int main()
{
    int r;
    map<string,int> mp;
    string fodase;
    scanf("%d",&r);
    for(int k = 0;k < r;k++)
    {
        EdgeList.clear();
        mp.clear();

        int sum = 0, m, n, RefNum = 1;


        scanf("%d %d",&n,&m);
        for (int i = 0;i < m;i++)
        {
            string x, y;
            int z;
            cin >> x >> y >> z;
            if(mp.find(x) == mp.end())
            {
                mp[x] = RefNum;
                RefNum++;

            }
            if(mp.find(y) == mp.end())
            {
                mp[y] = RefNum;
                RefNum++;

            }

            P[mp[x]] = mp[x];
            P[mp[y]] = mp[y];
            qtd[mp[x]] = 1;
            qtd[mp[y]] = 1;
            EdgeList.push_back(make_pair(z,ii(mp[x],mp[y])));
        }
        sort(EdgeList.begin(),EdgeList.end());
        for (int i = 0;i < m;i++)
        {
            if (Find(EdgeList[i].second.first) != Find(EdgeList[i].second.second))
            {
                unionSet(EdgeList[i].second.first,EdgeList[i].second.second);
                sum+=EdgeList[i].first;
            }
        }
        if (k == 0)
            cout << sum << endl;
        else
            cout << endl << sum << endl;
    }
}
