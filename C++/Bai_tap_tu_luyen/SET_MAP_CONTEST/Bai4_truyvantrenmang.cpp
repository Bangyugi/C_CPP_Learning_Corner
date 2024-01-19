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
    int thaoTac, q, x;
    cin >> q;
    while (q--)
    {
        cin >> thaoTac >> x;
        if (thaoTac == 1)
        {
            se.insert(x);
        }
        if (thaoTac == 2)
        {
            auto it = se.find(x);
            if (it != se.end())
            {
                se.erase(it);
            }
        }
        if (thaoTac == 3)
        {
            if (se.count(x))
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
}