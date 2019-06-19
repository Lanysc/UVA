#include <bits/stdc++.h>

using namespace std;

int main()
{ 
	int r, opcao,num,numV,cont,
		contPqu,contQu,contSt;
	while(scanf("%d",&r) != EOF)
	{
		cont = 0;
		contPqu = 0;
		contQu = 0;
		contSt = 0;
		queue <int> Qu;
		stack<int> st;
		priority_queue<int> Pqu;
		
		while(r--)
		{
			scanf("%d %d",&opcao,&num);
			if(opcao == 2)
				cont++;
			switch(opcao)
			{
				case 1:
					Qu.push(num);
					st.push(num);
					Pqu.push(num);
					break;
					
				case 2:
					if(!Qu.empty())
					{
						numV=Qu.front();
						Qu.pop();
						if (numV == num)
						{
							contQu++;
						}
					}
					if(!st.empty())
					{
						numV=st.top();
						st.pop();
						if (numV == num)
						{
							contSt++;
						}
					}
					
					if(!Pqu.empty())
					{
						numV=Pqu.top();
						Pqu.pop();
						if (numV == num)
						{
							contPqu++;
						}
						
					}
					break;
			}

		}
			if (contPqu != cont && contQu != cont && contSt != cont)
				printf("impossible\n");
			else if ((contPqu == contQu  && contPqu == cont)||
				(contPqu == contSt && contSt == cont)||
				(contQu == contSt && contQu == cont))
				printf("not sure\n");
			else if (contQu == cont)
				printf("queue\n");
			else if (contSt == cont)
				printf("stack\n");
			else if (contPqu == cont)
				printf("priority queue\n");
	}
}
