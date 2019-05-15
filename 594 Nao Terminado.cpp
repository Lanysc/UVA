#include <bits/stdc++.h>

using namespace std;

map <int,int> mp, pos;
list <int>  stl;
void Enq(int i)
{
    if(pos[mp[i]] == 1)
    {
        stl.push_back(i);
        pos[mp[i]] += 1;
    }
    else //adiciona no pos[mp[i]] o numero
    {

    }
}

void Deq()
{

}

void Stop()
{
    mp.clear();
    pos.clear();
    stl.clear();
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int i = 0;i < T;i++)
    {
        int Num;
        scanf("%d",&Num);
        while(Num--)
        {
            int y;
            scanf("%d",&y);
            mp[y] = i;
        }
        pos[i] = 1;
    }
    string Comando;
    cin >> Comando;
    if(Comando == "ENQUEUE")
    {
        int x;
        scanf("%d",x);
        Enq(x);
    }
    else if(Comando == "DEQUEUE")
        Deq();
    else
        Stop();


}
