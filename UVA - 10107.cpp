#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<long long int> vec;
	long long int x, median, half; 
	while(scanf("%lld",&x) != EOF)
	{
		vec.push_back(x);
		sort(vec.begin(), vec.end());

		if (vec.size() % 2 == 0)
		{
			half = (int)vec.size()/2;
			median = (vec[half-1] + vec[half])/2;	
		} 
		 else 
			median = vec[(int)vec.size() /2];	
		printf("%lld\n",median);
	}
}
