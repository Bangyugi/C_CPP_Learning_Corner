#include <bits/stdc++.h>
using namespace std;
int final = 0;

void sinh(string &s)
{
    int i = s.size() - 1;
    while (i >= 0 && s[i] == '1')
    {
        s[i] = '0';
        i--;
    }
    if (i >= 0)
        s[i] = '1';
}

int main()
{
    string s;
    cin >> s;
    sinh(s);
    cout << s;
    cout << endl;
}