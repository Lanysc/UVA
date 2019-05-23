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
    
    bool operator < (const Whells b) const
    {
        int x = v1 + (10 * v2) + (100 * v3) + (1000 * v4);
		int y = b.v1 + (10*b.v2) + (100 * b.v3) + (1000 * b.v4);
		return x < y;       
    }
    
    bool operator > (Whells b)
    {
        int x = v1 + (10*v2) + (100 * v3) + (1000 * v4);
		int y = b.v1 + (10*b.v2) + (100 * b.v3) + (1000 * b.v4);
		return x > y;       
    }
    
    bool operator != (Whells b)
    {
        if(v1 != b.v1 && v2 != b.v2 && v3 != b.v3 && v4 != b.v4)
            return true;
        return false;
    }
};

queue<Whells> Qu;
map<Whells, int> Proibido;

int A_[8] = {1,-1,0,0,0,0,0,0},
    B_[8] = {0,0,1,-1,0,0,0,0},
    C_[8] = {0,0,0,0,1,-1,0,0},
    D_[8] = {0,0,0,0,0,0,1,-1},
    botoes, node, nodeT;

void bfs(int a, int b, int c, int d)
{
    for (int i = 0; i < 8; i++)
    {
        a = abs(a) + A_[i];
        if (a == -1)
        	a = 9;
        else if (a == 10)
        	a = 0;
        b = abs(b) + B_[i];
        if (b == -1)
        	b = 9;
        else if (b == 10)
        	b = 0;
        c = c + C_[i];
        if (c == -1)
        	c = 9;
        else if (c == 10)
        	c = 0;
        d = d + D_[i];
        if (d == -1)
        	d = 9;
        else if (d == 10)
        	d = 0;
        if (Proibido[Whells(a,b,c,d)] == 0)
        {
        	//cout << a << b << c << d << endl;
            nodeT++;
            Proibido[Whells(a,b,c,d)] = 1;
            Qu.push(Whells(a,b,c,d));
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
        Proibido[Whells(Var1[0], Var1[1], Var1[2], Var1[3])] = 1;
        scanf("%d %d %d %d", &VarR[0], &VarR[1], &VarR[2], &VarR[3]);
        scanf("%d",&Pb);
        while(Pb--)
        {
			scanf("%d %d %d %d", &Var2[0], &Var2[1], &Var2[2], &Var2[3]);
			Proibido[Whells(Var2[0], Var2[1], Var2[2], Var2[3])] = 1;;
        }
        while(!ok && !Qu.empty())
        {
			int a = Qu.front().v1;
            int b = Qu.front().v2;
            int c = Qu.front().v3;
            int d = Qu.front().v4;
            Qu.pop();
            if (a == VarR[0] && b == VarR[1] && c == VarR[2] && d == VarR[3])
                ok = true;
            if (!ok)
            {
                bfs(a,b,c,d);
                node--;
                if (node <= 0)
                {
                    botoes++;
                    node = nodeT;
                    nodeT = 0;
                }
            }
		}
        if (ok)
            printf("%d\n\n",botoes);
        else 
            puts("-1");
        while(!Qu.empty())
            Qu.pop();
        Proibido.clear();
    }
}
