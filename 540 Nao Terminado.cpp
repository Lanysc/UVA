#include <bits/stdc++.h>
// o NUMERO NAO ESTA SENDO ALOCADO CORRETAMENTE 
using namespace std;
 
pair<int,int> fila[600000], numero;
int size = 0;
map<int,int> mp;
 
void Enq(pair<int,int>num)
{
    if(size == 0)
    {
        puts("entrei");
	    fila[0] = num;
    }	
    else
    {
        bool e = false, ok = false;
        for(int i = size-1;!ok && i >= 0;i--)
        {
            fila[i+1] = fila[i];
            if(e)
            {
                if(i == 0 || num.second != fila[i+1].second)
                {
                    fila[i+1] = num;
                    ok = true;
                }
            }
            else
            {
                if(fila[i].second == num.second)
                {
                    e = true;
                }
            }
            
        }
    }
    size++;
 
}
 
void Deq()
{
    cout << fila[size-1].second << endl;
    size--;
}
 
void Stop()
{
    size = 0;
}
 
int main()
{
    int T;
    while(scanf("%d",&T) && T != 0)
    {
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
	    }
	    string Comando;
	    while(Comando != "STOP")
		{
			cin >> Comando;
		    if(Comando == "ENQUEUE")
		    {
		        int x;
		        scanf("%d",&x);
		        numero.first = x;
		        numero.second = mp[x];
		        Enq(numero);
		    }
		    else if(Comando == "DEQUEUE")
		        Deq();
		    else
		        Stop();
		}
    }	
}
