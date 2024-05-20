#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
using namespace std;
ll MOD = 1e9 + 7;

int A(int m, int n){
    if (m==0)
        return n + 1;
    if (n==0)
        return A(m - 1, 1);
    return A(m - 1, A(m, n - 1));
}

int main()
{
    //ios_base::sync_with_stdio(NULL);
    //cin.tie(0);
    //cout.tie(0);
    cout << A(1, 2);
    return 0;
}