#include <bits/stdc++.h>

using namespace std;

int main()
{
	int r, aux, maior;
	while(scanf("%d",&r) && r != 0)
	{
		map<vector<int>,int> mp;
		aux = 0;
		maior = 0;
		while(r--)
		{
			vector<int> vec;
			int x[5];
			scanf("%d %d %d %d %d",&x[0],&x[1],&x[2],&x[3],&x[4]);
			for(int i = 0; i < 5; i++)
			{
				vec.push_back(x[i]);
			}
			sort(vec.begin(),vec.end());
			mp[vec]++;
		}
		for(map<vector<int>,int>::iterator i = mp.begin(); i != mp.end(); i++) 
		{
			//cout << i->second << endl;
			if(i->second > aux)
			{
				aux = i->second;
				maior = 0;
			}
			if(i->second == aux)
				maior += aux;
		}
		printf("%d\n",maior);
	}
}
