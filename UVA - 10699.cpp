#include <bits/stdc++.h>

using namespace std;


typedef vector<int> vi;
typedef long long ll;

long long _sieve_size;
bitset<10001000> bs;
vector<int> primes;

void sieve(long long upperbound)
{
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (long long i = 2;i <= _sieve_size;i++)
        if(bs[i])
        {
            for(long long j = i * i;j<= _sieve_size;j+=i)
                bs[j] = 0;
            primes.push_back((int)i);
        }

}
ll PrimeFactors(ll N)
{
    set<int> factors;
    ll PF_idx = 0, PF = primes[PF_idx];
    while(PF * PF <= N)
    {
        while(N % PF == 0)
        {
            N /= PF;
            factors.insert(PF);
        }
        PF = primes[++PF_idx];
    }
    if(N != 1)
        factors.insert(N);
    return (int)factors.size();
}

int main()
{
    sieve(10000000);
    ll cases;
    while(scanf("%lld",&cases) && cases != 0)
    {
		if (cases >= 2)
		{
			ll r = PrimeFactors(cases);
			cout << cases << " : " << r << endl;
		}
		else
			cout << "0"  << endl;       
    }

}
