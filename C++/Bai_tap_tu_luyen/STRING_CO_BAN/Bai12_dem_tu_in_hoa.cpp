#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    long long cnt = 0;
    while (cin>>s)
    {
        bool check = true;
        for (int i = 0; i < s.size(); i++)
        {
            if (islower(s[i]))
            {
                check = false;
                break;
            }
        }
        if (check)
        {
            cnt++;
        }
    }
    cout << cnt;
}