#include <bits/stdc++.h>
using namespace std;

void sinh(string &s, bool &final)
{
    int i = s.size() - 1;
    while (i >= 0 && s[i] == '-')
    {
        s[i] = '+';
        i--;
    }
    if (i == -1)
    {
        final = true;
    }
    else
    {
        s[i] = '-';
    }
}

int main()
{
    long long x, y, z, t;
    cin >> x >> y >> z >> t;
    string s = "+++";
    bool final = false;
    long long res = 0;
    while (!final)
    {
        long long temp = x;
        if (s[0] == '+')
            temp += y;
        else
            temp -= y;
        if (s[1] == '+')
            temp += z;
        else
            temp -= z;
        if (s[2] == '+')
            temp += t;
        else
            temp -= t;
        res = max(res, temp);
        sinh(s, final);
    }
    cout << res;
}