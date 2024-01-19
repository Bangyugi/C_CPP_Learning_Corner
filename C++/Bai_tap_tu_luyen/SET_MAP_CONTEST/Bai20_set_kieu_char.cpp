#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    set<char> se;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        se.insert(a[i]);
    }
    cout << se.size() << "\n";
    for (auto it = se.begin(); it != se.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    for (auto it = se.begin(); it != se.end(); it++)
    {
        cout << *it << " ";
    }
}