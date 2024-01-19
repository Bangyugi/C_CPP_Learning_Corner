#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<long long, int> mp;
    long long sum = 0;
    int ans = -1, start = -1;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum == 0)
        {
            ans = i + 1;
            start = 0;
        }
        if (mp.count(sum))
        {
            if (ans < i - mp[sum])
            {
                ans = i - mp[sum];
                start = mp[sum] + 1;
            }
        }
        if (mp.count(sum)==0)
        {
            mp[sum] = i;
        }
    }
    if (ans == -1)
    {
        cout << "NOT FOUND";
    }
    else
    {
        for (int i = 0; i < ans; i++)
        {
            cout << a[start+i] << " ";
        }
    }
}