#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,d;
    cin >> n >> d;
    long long a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long cnt = 0;
    for (int i = 1; i < n; i++)
    {
        while (a[i]<=a[i-1])
        {
            a[i] += d;
            cnt++;
        }
    }
    cout << cnt;
}