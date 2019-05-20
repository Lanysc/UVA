#include <bits/stdc++.h>

using namespace std;

int main()
{
    int nod,start,e,caso = 1;
    while(scanf("%d",&nod) && nod != 0)
    {
        vector<int> vec[100010], numeros;
        bool vi[100010];
        memset(vi,0,sizeof(vi));
        int quantia;
        quantia = 0;
        for(int i = 0;i < nod;i++)
        {
            int x, y;
            scanf("%d %d",&x,&y);
            vec[y].push_back(x);
            vec[x].push_back(y);
            if(!vi[x])
            {
                quantia++;
                numeros.push_back(x);
                vi[x] = true;
            }
            if(!vi[y])
            {
                quantia++;
                numeros.push_back(y);
                vi[y] = true;
            }

        }
        while(scanf("%d %d",&start,&e) && start != 0 || e != 0)
        {
            bool vistos[100010] = {};
            queue<int> Qu;
            int Tam, cont, contT, contAux;
            cont = 1;
            contAux = 0;
            Tam = 0;
            vistos[start] = true;
            Qu.push(start);
            contT = 0;
            for(int i = 1; !Qu.empty() && i <= e;i++)
            {
                while(cont--)
                {
                    int front = Qu.front();
                    Qu.pop();
                    int r = vec[front].size();
                    for(int j = 0;j < r;j++)
                    {
                        if(!vistos[vec[front][j]])
                        {
                            Tam++;
                            Qu.push(vec[front][j]);
                            vistos[vec[front][j]] = true;
                            contT++;
                        }
                        contAux++;
                    }
                    contAux = 0;
                }
                cont = contT;
                contT = 0;
            }
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",caso,quantia - Tam -1,start,e);
            caso++;
        }
    }
}
