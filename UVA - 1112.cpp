#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

typedef pair<int,int> ii;

int main()
{
    int cases, n ,m, s, t;
    scanf("%d",&cases);

    for(int k = 1; k <= cases; k++)
    {
        vector<ii>AdjList[20001];
        vector<int> dist(20001,INF);

        scanf("%d %d %d %d",&n,&s,&t,&m);
        while(m--)
        {
            int x, y, z;
            scanf("%d %d %d",&x,&y,&z);
            AdjList[y].push_back(make_pair(x,z));
        }

        priority_queue<ii,vector<ii>,greater<ii>> q;
        set<int>st;
        dist[s] = 0;
        q.push(ii(0,s));
        st.insert(s);
        while(!q.empty())
        {
            int u = q.top().second;
            q.pop();
            for (int i = 0;i < (int)AdjList[u].size();i++)
            {
                ii v = AdjList[u][i];
                if (dist[u] + v.second <= t)
                {
                    st.insert(v.first);
                }

                if ((dist[u] + v.second < dist[v.first]))
                {
                    dist[v.first] = dist[u] + v.second;
                    q.push(ii(dist[v.first],v.first));
                }
            }
        }
        if (k == 1)
            printf("%d\n",(int)st.size());
        else
            printf("\n%d\n",(int)st.size());
    }

}
