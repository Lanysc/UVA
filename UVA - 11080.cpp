#include <stdio.h>
#include <queue>
#include <set>
#include <vector>
#include <iostream>

#define INF 1e9


using namespace std;


typedef pair<int, int> ii;
typedef vector<int> vi;

int main()
{
	int n, e, cases;
	int x, y, menor;
	cin >> cases;
	
	while (cases--)
	{
		vi adjList[200];
		cin >> n >> e;
		for (int i = 0; i < e; i++)
		{
			cin >> x >> y;
			adjList[x].push_back(y);
			adjList[y].push_back(x);
		}
		
		queue<int> q;
		vi color(n, INF);
		menor = 0;
		
		bool isBipartite = true;
		
		for (int i = 0; i < n; i++)
		{
			if(color[i] == INF)
			{
				int cont1 = 0, cont0 = 0;
				q.push(i);
				color[i] = 0;
				cont0++;
				while (!q.empty() && isBipartite)
				{
					int u = q.front();
					q.pop();
					for (int i = 0; i < (int)adjList[u].size(); i++)
					{
						int v = adjList[u][i];
						if (color[v] == INF)
						{
							color[v] = 1 - color[u];
							if (color[v] == 1)
								cont1++;
							else 
								cont0++;
							q.push(v);
						}
						else if (color[v] == color[u])
						{
							isBipartite = false;
							break;
						}
					}
				}
				menor += max(1,min(cont1,cont0));
			}
		}
		
		
		

		if (isBipartite)
			cout << menor << endl;
		else
			cout << -1 << endl;
	}
}
