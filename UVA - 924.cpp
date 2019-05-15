#include <bits/stdc++.h>

using namespace std;

vector<int> vec[2501];

void bfs(int start, int e)
{
	bool vistos[2501] = {};
	queue<int> Qu;
	int Dia, Tam, cont, contT, contAux;
	cont = 1;
	contAux = 0;
	Tam = 0;
	Dia = 1;
	vistos[start] = true;
	Qu.push(start);
	contT = 0;
	for(int i = 1; !Qu.empty() && i <= e;i++)
	{
		while(cont--)
		{	
			int front = Qu.front();
			Qu.pop();
			int r = vec[front].size();
			for(int j = 0;j < r;j++)
			{
				if(!vistos[vec[front][j]])
				{
					Qu.push(vec[front][j]);
					vistos[vec[front][j]] = true;
					contT++;
				}
				contAux++;
			}
			if(contT > Tam)
			{
				Tam = contT;
				Dia = i;
			}
			contAux = 0;
		}
		cont = contT;
		contT = 0;
	}
	if(Tam == 0)
		puts("0");
	else
		printf("%d %d\n",Tam,Dia);
}

int main() 
{
	int emp, testcase;
	scanf("%d",&emp);
	for(int i = 0;i < emp;i++)
	{
		int friends;
		scanf("%d",&friends);
		while(friends--)
		{
			int x;
			scanf("%d",&x);
			vec[i].push_back(x);
		}
	}
	scanf("%d",&testcase);
	while(testcase--)
	{
		int y;
		scanf("%d",&y);
		bfs(y,emp);
	}
}
