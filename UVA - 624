#include <bits/stdc++.h>

using namespace std;

vector<int> ans,vet,music;
int N,M,sum,sum_max = 0;

void dfs(int idx, int sum)
{
	if (sum > N) return;
	if (sum > sum_max)
	{
		sum_max = sum;
		ans = vet;
	}
	if (sum_max == N) return;
	if (idx == M) return;
	dfs(idx+1,sum);
	vet.push_back(music[idx]);
	dfs(idx+1,sum + music[idx]);
	vet.pop_back();
}
int main()
{
	int num;
	scanf("%d %d",&N,&M);
	for (int i = 1; i <= M; i++)
	{
		scanf("%d",&num);
		music.push_back(num);
	}
	dfs(0,0);
	for (int i = 0; i < (int)ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
	printf("sum:%d\n",sum_max);
	
}
