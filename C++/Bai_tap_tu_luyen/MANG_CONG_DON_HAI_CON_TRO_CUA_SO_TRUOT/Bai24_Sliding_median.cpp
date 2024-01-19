#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    multiset<int> se;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < k; i++)
    {
        se.insert(a[i]);
    }
    auto it = se.begin();
    it += k / 2;
    cout << *it << " ";
    for (int i = k; i < n; i++)
    {
        se.insert(a[i]);
        se.erase(a[i - k]);
        cout << (*se.rbegin() + *se.begin()) / 2 << " ";
    }
}