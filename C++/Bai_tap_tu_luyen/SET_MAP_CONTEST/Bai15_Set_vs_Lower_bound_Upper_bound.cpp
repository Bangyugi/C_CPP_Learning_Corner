#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    multiset<int> se;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        se.insert(a[i]);
    }

    int q, thaotac, x;
    cin >> q;
    while (q--)
    {
        cin >> thaotac >> x;
        if (thaotac == 1)
        {
            se.insert(x);
        }
        if (thaotac == 2)
        {
            auto it = se.find(x);
            if(it!=se.end())
            se.erase(it);
        }
        if (thaotac == 3)
        {
            auto it1 = se.lower_bound(x);
            if (it1 != se.end())
            {
                cout << *it1 << "\n";
            }
            else
            {
                cout << -1 << "\n";
            }
        }
        if (thaotac == 4)
        {
            auto it2 = se.upper_bound(x);
            if (it2 != se.begin())
            {
                it2--;
                cout << *it2 << "\n";
            }
            else
            {
                cout << -1 << "\n";
            }
        }
    }
}