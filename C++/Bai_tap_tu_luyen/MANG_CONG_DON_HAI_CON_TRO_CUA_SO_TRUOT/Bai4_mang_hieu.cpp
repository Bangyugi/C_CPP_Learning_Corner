#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long a[n + 1];
    a[0] = 0;
    long long D[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        D[i] = a[i] - a[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        cout << D[i] << " ";
    }
    
}