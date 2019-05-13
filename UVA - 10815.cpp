#include <bits/stdc++.h>
#include <cctype>
using namespace std;

int main()
{
    string str;
    set<string> words;
    
    while (cin >> str)
    {
        int size = str.size();
        
        string current = "";
        for (int i = 0; i < size; ++i)
        {
            char c = tolower(str[i]);
            if (c >= 'a' && c <='z')
                current += c;
            else if (current != "")
            {
                words.insert(current);
                current = "";
            }
        }
        if (current != "")
            words.insert(current);
    }
    
    for (set<string>::iterator iter = words.begin(); iter != words.end(); ++iter)
        cout << *iter << '\n';
}
