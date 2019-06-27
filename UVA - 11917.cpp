#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("teste.txt","w",stdout);
	int r, r1;
	map <string,int> mp;
	scanf("%d",&r);
	for (int i = 1;i <= r;i++)
	{
		mp.clear();
		string materia;
		int tempo, prazo;
		scanf("%d",&r1);
		while(r1--)
		{
			cin >> materia >> tempo;
			mp[materia] = tempo;
		}
		scanf("%d",&prazo);
		cin >> materia;
		if(mp.find(materia) != mp.end())
		{
			if(mp[materia] <= prazo)
			{
				printf("Case %d: Yesss\n",i);
			}
			else if (mp[materia] <= 5 + prazo)
			{
				printf("Case %d: Late\n",i);
			}
			else 
			{
				printf("Case %d: Do your own homework!\n",i);
			}
		}
		else 
			printf("Case %d: Do your own homework!\n",i);	
	}
	
}