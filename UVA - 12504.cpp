#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("arvores.txt","w",stdout);
	int repetir, j = 0,cont;
	bool pal, num;
	string d1,d2, word, palavras[10000], numero, ww;
	scanf("%d",&repetir);
	while(repetir--)
	{
		map<string,string> mp, mp2;
		set<string> mais,menos,mudo;
		j = 0;
		pal = true;
		num = false;
		word = "";
		numero = "";
		cin >> d1 >> d2;
		for(int i = 1;i < (int)d1.size();i++)
		{
			if (d1[i] == ',' || (i == (int)d1.size()-1 && d1.size() > 2))
			{
				mp[word] = numero;
				word = "";
				numero = "";
				pal = true;
				num = false;
				j++;
			}
			else if (d1[i] == ':')
			{
				palavras[j] = word;
				pal = false;
				num = true;
			}
			else if (pal)
			{
				word += d1[i];
			}
			else if (num)
			{
				numero += d1[i];
			}
		}
		word = "";
		numero = "";
		pal = true;
		num = false;
		for(int i = 1;i < (int)d2.size();i++)
		{
			if (d2[i] == ',' || (i == (int)d2.size()-1 && d2.size() > 2))
			{
				if (mp.find(word) != mp.end())
				{
					if(mp[word] != numero)
					{
						mudo.insert(word);
					}
				}	
				else
				{
					mais.insert(word);
				}
				
				mp2[word] = numero;
				word = "";
				numero = "";
				pal = true;
				num = false;
			}
			else if (d2[i] == ':')
			{
				pal = false;
				num = true;
			}
			else if (pal)
			{
				word += d2[i];
			}
			else if (num)
			{
				numero += d2[i];
			}
		}
		
		for(int i = 0; i < j; i++)                           
		{                                                     
			if (mp2.find(palavras[i]) == mp2.end())           
			{                                                 
				menos.insert(palavras[i]);                     
			} 
			palavras[i] = "";                                                
		}                                                     
		
		cont = 0;
		if (!mais.empty())
		{
			cout << "+";
			for (set<string>::iterator it=mais.begin(); it!=mais.end(); ++it)
			{
				if (cont == 0)
      	  		{
      	  			cout << *it;
					cont++;
				}
 				else
				 	cout << "," << *it;  
			} 
			cout << endl;
		}
	   	cont = 0;
		if (!menos.empty())
		{
			cout <<"-";
			for (set<string>::iterator it=menos.begin(); it!=menos.end(); ++it)
			{
				if (cont == 0)
      	  		{
      	  			cout << *it;
					cont++;
				}
 				else
				 	cout << "," << *it;  
			} 
			cout << endl;
		}
		cont = 0;
		if (!mudo.empty())
		{
			cout << "*";
			for (set<string>::iterator it=mudo.begin(); it!=mudo.end(); ++it)
			{
				if (cont == 0)
				{
      	  			cout << *it;
					cont++;
				}
 				else
				 	cout << "," << *it;  
			} 
			cout << endl;
		}
		if (mudo.empty()&&
			menos.empty()&& 
			mais.empty())		
			cout << "No changes\n";
		cout << endl;	
	}
}