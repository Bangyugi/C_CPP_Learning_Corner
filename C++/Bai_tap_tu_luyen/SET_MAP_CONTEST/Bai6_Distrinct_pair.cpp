#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int x, y;
    set<pair<int, int>> se;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        se.insert({x, y});
    }
    cout << se.size();
}