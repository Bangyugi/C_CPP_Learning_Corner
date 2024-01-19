#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n + 1];
    set<int> se;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        se.insert(a[i]);
    }
    vector<vector<int>> res;

    vector<int> v;
    for (auto x : se)
    {
        v.push_back(x);
    }
    do
    {
        res.push_back(v);
    } while (next_permutation(v.begin(), v.end()));
    sort(res.begin(), res.end(), greater<vector<int>>());
    for (auto x : res)
    {
        for (auto z : x)
        {
            cout << z << " ";
        }
        cout << endl;
    }
}