#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
typedef pair<int,int> ii;
typedef pair<int,pair<int,int> > iii;

int dc[] = {1,0,-1,0};
int dl[] = {0,1,0,-1};

int main()
{
	int r, c, P[1000][1000], R[1000][1000], cases;
	scanf("%d", &cases);
	while (cases--)
	{
		priority_queue<iii,vector<iii>,greater<iii> > q;
		scanf("%d %d",&r,&c);
		for(int i = 0; i < r; i++)
			for(int j = 0; j < c; j++)
			{
				scanf("%d",&P[i][j]);
			}
		for(int i = 0; i < 1000; i++)
			for(int j = 0; j < 1000; j++)
			{
				R[i][j] = INF;
			}
		R[0][0] = P[0][0];
		q.push(make_pair(P[0][0],ii(0,0)));
		while(!q.empty())
		{
			int x = q.top().second.first;
			int y = q.top().second.second;
			q.pop();
			
			for(int i = 0; i < 4; i++)
			{
				if ((x + dl[i] >= 0 && x + dl[i] < r) && 
					(y + dc[i] >= 0 && y + dc[i] < c) &&
					(P[x + dl[i]][y + dc[i]] + R[x][y] < R[x + dl[i]][y + dc[i]]))
				{
					R[x + dl[i]][y + dc[i]] = P[x + dl[i]][y + dc[i]] + R[x][y];
					q.push(make_pair(R[x + dl[i]][y + dc[i]],ii(x+dl[i],y+dc[i])));
				}
			}
		}
		printf("%d\n",R[r-1][c-1]);
	}
	
}
