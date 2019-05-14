#include <bits/stdc++.h>

using namespace std;

int long long NewNum, bit0, bit1, bit2, bit3;

void Separa_bit(long long int Num)
{
	bit3 = (Num >> 24) & 255;
	bit2 = (Num >> 16) & 255;
	bit1 = (Num >> 8) & 255;
	bit0 = Num & 255;
}

int main() 
{
	int long long Num;
	while (scanf("%lld",&Num) == 1) 
	{
		Separa_bit(Num);
		NewNum = (bit2 << 8) + (bit1 << 16) + (bit0 << 24) + bit3;
		
		int aux = (bit0 >> 7) << 30;
		for (int i = 31; i <= sizeof(long long int) * 8 - 1; i++) 
		{
			aux = aux << 1;
			NewNum = NewNum | aux;
		}
		
		printf("%lld converts to %lld\n",Num,NewNum);
	}
}
