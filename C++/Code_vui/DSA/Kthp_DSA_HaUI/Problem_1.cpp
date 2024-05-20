#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

int F(int m, int n)
{
    if (m < 0)
        return abs(m);
    if (n <= 0)
        return F(m - 3, 1);
    return F(m - 4, n) + F(m, n - 2);
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    cout << F(5, 2);
    return 0;
}