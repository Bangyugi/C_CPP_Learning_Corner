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
    cout << se.size() << endl;
    auto it1 = se.begin();
    auto it2 = se.end();
    it2--;
    cout << *it2 << " " << *it1 << endl;

    cout << *(--it2) << " " << *(++it1) << endl;
}