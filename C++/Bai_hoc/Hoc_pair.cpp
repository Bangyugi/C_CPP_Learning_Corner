#include <bits/stdc++.h>
using namespace std;

int main()
{
    pair<int, int> p1;
    pair<int, long long> p2;
    pair<int, int> p3 = make_pair(10, 20);
    cout << p3.first << " " << p3.second << "\n";
    pair<int, int> p4 = {20, 30};
    cout << p4.first << " " << p4.second << "\n";

    int n;
    cin >> n;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i].first << " " << a[i].second << "\n";
    }
}