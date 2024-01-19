#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    set<int> se;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (!se.count(a[i]))
            se.insert(a[i]);
        else
        {
            cout << a[i];
            return 0;
        }
    }
    cout << -1;
}