#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	string name,aux;
	while (cin >> name  && name != "#")
	{
		aux = name;
		if (next_permutation(aux.begin(),aux.end())) 
			cout << aux << endl;
		else
			cout << "No  Successor" << endl;
	}
}
