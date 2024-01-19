#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

int find(ll n, ll k)
{
    if (n == 1)
    {
        return 1;
    }
    if (k < pow(2, n - 1))
    {
        return find(n - 1, k);
    }
    else if (k > pow(2, n - 1))
    {
        return find(n - 1, k - pow(2, n - 1));
    }
    else
    {
        return n;
    }
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);

    ll n, k;
    cin >> n >> k;
    cout << find(n, k) << endl;
    return 0;
}