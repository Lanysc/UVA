#include <bits/stdc++.h>

using namespace std;

bool org (int i, int j)
{
	return i > j;
}

int main()
{
	int r;
	while(scanf("%d",&r) && r != 0)
	{
		priority_queue<int, vector<int>, greater<int> > vec;
		int soma = 0;
		while(r--)
		{
			int num;
			scanf("%d",&num);
			vec.push(num);
		}
		while((int)vec.size() > 1)
		{
			int first = vec.top();
			vec.pop();
			int second = vec.top();
			vec.pop();
			soma += first + second;
			vec.push(first + second);
		}
		cout << soma << endl;
	}
}
