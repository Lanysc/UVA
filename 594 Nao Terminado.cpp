#include <bits/stdc++.h>

using namespace std;

int T;
map <int,int> mp, pos;
list <int>  stl;
list <int>::iterator it;

void Enq(int i)
{
    if(pos[mp[i]] <= 1)
    {
        stl.push_back(i);
        pos[mp[i]] += stl.size();
    }
    else //adiciona no pos[mp[i]] o numero
    {
        it = stl.begin();
        advance(it,pos[mp[i]]);
        stl.insert(it,i);
        pos[mp[i]] += pos[mp[i]];
    }
}

void Deq()
{
    printf("%d\n",stl.front());
    stl.pop_front();
    for (int i = 0;i < T;i++)
    {
        pos[i]= pos[i]-1;
    }
}

void Stop()
{
    mp.clear();
    pos.clear();
    stl.clear();
}

int main()
{
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
