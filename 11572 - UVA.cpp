#include <bits/stdc++.h>

using namespace std;

int main()
{
	int aux, r, nc, cont, contT;
	scanf("%d",&r);
	while(r--)
	{
		map<int,int> mp;
		scanf("%d",&nc);
		cont = 0;
		contT = 0;
		aux = 0;
		bool vai = false;
		for(int i = 0; i < nc ;i++)
		{
			int Number;
			scanf("%d",&Number);
			if(mp.find(Number) != mp.end())
			{
				if(mp[Number] < aux && vai == true)
				{
					mp[Number] = i;
					cont++;
				}
				else
				{
					aux = mp[Number];
					mp[Number] = i;
					if (cont > contT)
					{
						contT = cont;
					}
					cont = i - aux;
				}
				vai = true;
			}	
			else 
			{
				mp[Number] = i;
				cont++;
			}  		
		}
		if (cont > contT)
		{
			contT = cont;
		}
		cout << contT << endl;
	}
	
}