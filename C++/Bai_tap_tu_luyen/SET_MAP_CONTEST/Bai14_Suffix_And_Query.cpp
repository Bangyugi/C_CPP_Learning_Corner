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
    set<int> se;
    int p[n];
    for (int i = n - 1; i >= 0; i--)
    {
        se.insert(a[i]);
        // for (auto x : se)
        // {
        //     cout << x << " ";
        // }
        // cout << "\n";
        p[i] = se.size();
    }
    int q, l;
    cin >> q;
    while (q--)
    {
        cin >> l;
        cout << p[l] << "\n";
    }
}