#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
using namespace std;
ll MOD = 1e9 + 7;

ll Comb(int n, int k)
{
    ll res = 1;
    for (int i = 1; i <= k;i++)
    {
        res *= (n - i + 1);
        res /= i;
    }
    return res;
}

int main()
{
    //ios_base::sync_with_stdio(NULL);
    //cin.tie(0);
    //cout.tie(0);
    int n, k;
    cin >> n >> k;
    cout << Comb( n + k - 1,k);
    return 0;
}