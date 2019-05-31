#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};
int R,C;
char grid[51][51];

int floodfill(int r,int c,char c1, char c2)
{
	if(r < 0 || r >= R || c < 0 || c >= C) return 0;
	if(grid[r][c] != c1) return 0;
	grid[r][c] = c2;
	int ans = 1;
	for (int i = 0; i < 4; i++)
		ans += floodfill(r + dr[i], c + dc[i], c1, c2);
	return ans;
}

int main()
{
	vector<pair<int,int> > vec;
	scanf("%d %d",&R,&C);
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			cin >> grid[i][j];
			if(grid[i][j] == 'T')
				vec.push_back(make_pair(i,j));
		}
	for (int i = 0; i < (int)vec.size(); i++)
	{
		int x = vec[i].first;
		int y = vec[i].second;
		floodfill(x,y,'A','T');
	}
	
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << grid[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
