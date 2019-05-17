#include <bits/stdc++.h>
// o NUMERO NAO ESTA SENDO ALOCADO CORRETAMENTE 
using namespace std;

int T, front = 0,x = -1;
map <int,int> mp, pos;
vector <int>  stl;

void Enq(int num)
{
    if(pos[mp[num]] <= 0)
    {
    	//puts("entrei 1");
        stl.push_back(num);
        pos[mp[num]] = stl.size();
    }
    else //adiciona no pos[mp[num]] o numero
    {
    	puts("entrei 2");
    	for (int i = stl.size()-1;i > pos[mp[num]];i--)
		{
			stl[i+1] = stl[i];
			if (pos[mp[i]] != x)
			{
				pos[mp[i]] += 1;
				x = pos[mp[i]];
			}
		}
		stl[pos[mp[num]]] = num;
		pos[mp[num]] = pos[mp[num]] + 1;
	}
}

void Deq()
{
    printf("%d %d %d\n",stl[0],stl[1],stl[2]);
    for(int i = 0; i < T; i++)
	{
		if (pos[i] > 0)
			pos[i] -= 1;
	}
	stl.erase(stl.begin());
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
        pos[i] = 0;
    }
    string Comando;
    while(Comando != "STOP")
	{
		cin >> Comando;
	    if(Comando == "ENQUEUE")
	    {
	        int x;
	        scanf("%d",&x);
	        Enq(x);
	    }
	    else if(Comando == "DEQUEUE")
	        Deq();
	    else
	        Stop();
	}
}
