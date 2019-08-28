#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<unsigned int> vt;
typedef pair<int, int> ii;

vt P(20000, 0);
vt qtd(20000, 1);


unsigned int Find(unsigned int u)
{
	if (u == P[u])
		return u;
	return Find(P[u]);
}

void unionSet(unsigned int a, unsigned int b)
{
	a = Find(a);
	b = Find(b);
	if (qtd[a] > qtd[b])
	{
		P[b] = a;
		qtd[a] += qtd[b];
	}
	else
	{
		P[a] = b;
		qtd[b] += qtd[a];
	}
}

int main()
{
	int sum = 0, m, n, sumT;
	while (scanf("%d %d", &n, &m) && n && m)
	{
		sum = 0;
		sumT = 0;
		vector<pair<int, ii>> EdgeList;
		for (int i = 0; i < m; i++)
		{
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			P[x] = x;
			P[y] = y;
			EdgeList.push_back(make_pair(z, ii(x, y)));
			sumT += z;
		}
		sort(EdgeList.begin(), EdgeList.end());
		for (int i = 0; i < m; i++)
		{
			if (Find(EdgeList[i].second.first) != Find(EdgeList[i].second.second))
			{
				unionSet(EdgeList[i].second.first, EdgeList[i].second.second);
				sum += EdgeList[i].first;
			}
		}
		for (int i = 0; i < n; i++)
		{
			P[i] = 0;
			qtd[i] = 1;
		}
		cout << sumT-sum << endl;
	}
}
