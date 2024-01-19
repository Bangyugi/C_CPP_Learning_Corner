#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    string s = to_string(n);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '6' && s[i] != '8' && s[i] != '0')
        {
            cout << 0;
            return 0;
        }
    }
    cout << 1;
}