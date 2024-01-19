#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        }
    for (int i = 0; i < n; i++)
    {
        if (mp.count(k - a[i]))
        {
            cout << "YES";
            return 0;
        }
        mp.insert({a[i], 1});
    }
    cout << "NO";
}