#include <bits/stdc++.h>

using namespace std;

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
    
    bool operator != (Whells b)
    {
        if(v1 != b.v1 && v2 != b.v2 && v3 != b.v3 && v4 != b.v4)
            return true;
        return false;
    }
};

queue<Whells> Qu;
vector<Whells> Proibido;
int A_[8] = {1,-1,0,0,0,0,0,0},
    B_[8] = {0,0,1,-1,0,0,0,0},
    C_[8] = {0,0,0,0,1,-1,0,0},
    D_[8] = {0,0,0,0,0,0,1,-1},
    botoes, node, nodeT;

bool verificar (Whells a)
{
    int i, size;
    size = (int)Proibido.size();
    for (i = 0;a != Proibido[i] && i < size; i++);
    if (i < (int)Proibido.size())
        return false;
    return true;
}

void bfs(int a, int b, int c, int d)
{
    for (int i = 0; i < 8; i++)
    {
        a = (abs(a) + A_[i]) % 10;
        b = (abs(b) + B_[i]) % 10;
        c = (abs(c) + C_[i]) % 10;
        d = (abs(d) + D_[i]) % 10;
        printf("%d %d %d %d\n",a,b,c,d);
        if (verificar(Whells(a,b,c,d)))
        {
            puts ("entrei");
            Qu.push(Whells(a,b,c,d));
            Proibido.push_back(Whells(a,b,c,d));
            nodeT++;
        }
    }
}

int main()
{
    int test, Var1[4], Var2[4], VarR[4];
    scanf("%d",&test);
    while(test--)
    {
        int Pb;
        botoes = 0;
        node = 0;
        nodeT = 0;
        bool ok = false;
        scanf("%d %d %d %d", &Var1[0], &Var1[1], &Var1[2], &Var1[3]);
        Qu.push(Whells(Var1[0], Var1[1], Var1[2], Var1[3]));
        scanf("%d %d %d %d", &VarR[0], &VarR[1], &VarR[2], &VarR[3]);
        scanf("%d",&Pb);
        while(Pb--)
        {
			scanf("%d %d %d %d", &Var2[0], &Var2[1], &Var2[2], &Var2[3]);
			Proibido.push_back(Whells(Var2[0], Var2[1], Var2[2], Var2[3]));
        }
        while(!ok && !Qu.empty())
        {
			int a = Qu.front().v1;
            int b = Qu.front().v2;
            int c = Qu.front().v3;
            int d = Qu.front().v4;
            printf("%d %d %d %d\n",a,b,c,d);
            Qu.pop();
            if (a == VarR[0] && b == VarR[1] && c == VarR[2] && d == VarR[3])
                ok = true;
            if (!ok)
            {
                bfs(a,b,c,d);
                if (node <= 0)
                {
                    node = nodeT;
                    botoes++;
                }
            }
		}
        if (ok)
            printf("%d\n",botoes);
        else 
            puts("-1");
        while(!Qu.empty())
            Qu.pop();
        Proibido.clear();
    }
}
