#include <stdio.h>
#include <queue>
#include <vector>
#include <iostream>

#define INF 1e9


using namespace std;


typedef pair<int, int> ii;
typedef vector<int> vi;

int main()
{
	int n, e;
	int x, y;
	while (cin >> n && n)
	{
		vi adjList[200];
		cin >> e;
		for (int i = 0; i < e; i++)
		{
			
			cin >> x >> y;
			adjList[x].push_back(y);
			adjList[y].push_back(x);
		}
		
		queue<int> q;
		q.push(x);
		vi color(n, INF);
		color[x] = 0;
		bool isBipartite = true;
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
					q.push(v);
				}
				else if (color[v] == color[u])
				{
					isBipartite = false;
					break;
				}
			}
		}

		if (isBipartite)
			cout << "BICOLORABLE.\n";
		else
			cout << "NOT BICOLORABLE.\n";
	}
}
