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

void bfs(int a, int b, int c, int d)
{

}

int main()
{
    queue<Whells> Qu;
    int test, a, b, c, d;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        Qu.push(Whells(a, b, c, d));
        scanf("%d %d %d %d", &a, &b, &c, &d);

    }

}
