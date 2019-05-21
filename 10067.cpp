#include <bits/stdc++.h>

using namespace std;

vector<Whells> Proibido;

struct Whells
{
    int v1, v2, v3, v4;
    Whells()
    {
    }
    Whells (int V1, int V2, int V3, int V4)
    {
        v1 = V1;
        v2 = V2;
        v3 = V3;
        v4 = V4;
    }
    bool operator == (Whells b)
    {
        if(v1 == b.v1 && v2 == b.v2 && v3 == b.v3 && v4 == b.v4)
            return true;
        return false;
    }
};

bool verificar (Whells a)
{
    int i;
    for (i = 0;Whells a != Whells b && i < (int)Proibidos.size(); i++);
    if (i < (int)Proibidos.size())
        return false
    return true
}

void bfs(int a, int b, int c, int d)
{

}

int main()
{
    queue<Whells> Qu;
    int test, Var1[4], Var2[4];
    scanf("%d",&test);
    while(test--)
    {
        int Pb;
        bool ok;
        scanf("%d %d %d %d", &Var1[0], &Var1[1], &Var1[2], &Var1[3]);
        Qu.push(Whells(a, b, c, d));
        scanf("%d %d %d %d", &Var1[0], &Var1[1], &Var1[2], &Var1[3]);
        scanf("%d",&Pb);
        while(Pb--)
        {
			scanf("%d %d %d %d", &Var2[0], &Var2[1], &Var2[2], &Var2[3]);
			Proibido.push_back(Whells(Var2[0], Var2[1], Var2[2], Var2[3]));
        }
        while(!ok && !Qu.empty())
        {
			
		}
    }

}
