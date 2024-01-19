#include <bits/stdc++.h>
using namespace std;

void sinh(string &s, bool &final)
{
    int i = s.size() - 1;
    while (i >= 0 && s[i] == '8')
    {
        s[i] = '0';
        i--;
    }
    if (i == -1)
    {
        final = true;
    }
    else
    {
        s[i] = '8';
    }
}

int main()
{
    int n = 19;
    vector<long long> res;
    string s;
    s = string(n, '0');
    s[n - 1] = '8';
    bool final = false;
    while (!final)
    {
        res.push_back(stoll(s));
        sinh(s, final);
    }
    // for (auto x : res)
    // {
    //     cout << x << endl;
    // }
    long long a[301];
    for (int i = 1; i <= 300; i++)
    {
        for (auto x : res)
        {
            if (x % i == 0)
            {
                a[i] = x;
                break;
            }
        }
    }
    int t, x;
    cin >> t;
    while (t--)
    {
        cin >> x;
        cout << a[x] << endl;
    }
}