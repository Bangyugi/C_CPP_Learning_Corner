#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    map<int, int> mp;
    int distance = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        int target1 = k + a[i];
        int target2 = a[i] - k;

        if (mp.find(target1) != mp.end())
        {
            distance = max(distance, i - mp[target1]);
        }
        if (mp.find(target2) != mp.end())
        {
            distance = max(distance, i - mp[target2]);
        }
        if (mp.find(a[i]) == mp.end())
        {
            mp[a[i]] = i;
        }
    }
    cout << distance;
}