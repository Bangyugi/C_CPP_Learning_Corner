#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;
vector<int> v;

int main()
{
    int n;
    cin >> n;
    while (n > 0)
    {
        if (n % 7 == 0)
        {
            v.push_back(7);
            n -= 7;
        }
        else
        {
            v.push_back(4);
            n -= 4;
        }
    }
    if (n == 0)
    {
        for (auto x : v)
        {
            cout << x;
        }
    }
    else
    {
        cout << -1;
    }
    return 0;
}