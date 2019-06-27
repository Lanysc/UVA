#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("teste.txt","w",stdout);
	int r, valor, custo, receitas, produtos, quantia;
	string name, prod, recName;
	scanf("%d",&r);
	while(r--)
	{
		cin.ignore();
		getline(cin,name);
		bool ok = false;
		map <string, int> mp;
		set < pair<int,string> >recipes;
		scanf("%d %d %d", &produtos, &receitas, &custo);
		
		while(produtos--)
		{
			cin >> prod >> valor;
			mp[prod] = valor;
		}
		
		while(receitas--)
		{
			   valor = 0;
			   int x;
			   cin.ignore();
			   getline(cin,recName);
			   cin >> x;
			   while(x--)
			   {
				   cin >> prod >> quantia;
				   valor += mp[prod] * quantia;      
			   }
			   if (valor <= custo)
			   {
			   	   recipes.insert(make_pair(valor,recName));		       			  
			   	
			   }
		}
		for(int i = 0; i < (int)name.length(); i++)
		{
			if (name[i] != ' ')
			{
				char ch = toupper(name[i]);
				cout << ch;
			}
			else 
				cout << name[i];
			
		}
		cout << endl;
		for(set <pair<int,string> >::iterator it = recipes.begin(); it != recipes.end(); it++)
		{
				cout << it->second << endl;
				ok = true;
		}	  		  		
		if(!ok)
		{
			cout << "Too expensive!\n";
		}
		cout << endl;
	}
	
}