#include <bits/stdc++.h>
using namespace std;

int main()
{
    // set: lưu các phần tử riêng biệt sắp xếp theo thứ tự tăng dần
    int n;
    cin >> n;
    long long a[n];
    set<long long> se;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        se.insert(a[i]);
    }

    for (auto it = se.begin(); it != se.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n";

    for (auto it = se.rbegin(); it != se.rend(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n";

    long long t, x;
    cin >> t;
    while (t--)
    {
        cin >> x;
        if (se.find(x) != se.end())
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
        if (se.count(x))
        {
            cout << "FOUND\n";
        }
        else
        {
            cout << "NOT FOUND\n";
        }
    }
    cout << "\n";

    int xoa;
    cin >> xoa;
    if (se.count(xoa))
    {
        se.erase(xoa);
    }
    for (auto it = se.begin(); it != se.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n";

    // Multiset: lưu các phần tử trùng nhau sắp xếp theo thứ tự tăng dần
    multiset<int> mse;
    int y;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> y;
        mse.insert(y);
    }
}