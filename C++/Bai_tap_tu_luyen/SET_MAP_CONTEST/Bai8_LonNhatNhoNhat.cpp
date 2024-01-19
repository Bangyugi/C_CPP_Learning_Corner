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
        se.insert(a[i]);
    }
    int q;
    cin >> q;
    while (q--)
    {
        auto it1 = se.begin();
        auto it2 = se.end();
        it2--;
        int thaoTac, x;
        cin >> thaoTac;
        if (thaoTac == 1)
        {
            cin >> x;
            se.insert(x);
        }
        if (thaoTac == 2)
        {
            cin >> x;
            se.erase(x);
        }
        if (thaoTac == 3)
        {
            cout << *it1 << "\n";
        }
        if (thaoTac == 4)
        {
            cout << *it2 << "\n";
        }
    }
}