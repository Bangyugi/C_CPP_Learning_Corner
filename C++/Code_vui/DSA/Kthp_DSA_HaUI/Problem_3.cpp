#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
using namespace std;
ll MOD = 1e9 + 7;

int F(int n){
    if (n<=0){
        return 0;
    }
    else
    {
        return 2 * n + F(n - 1);
    }
}

int main()
{
    //ios_base::sync_with_stdio(NULL);
    //cin.tie(0);
    //cout.tie(0);
    cout << F(5);
    return 0;
}