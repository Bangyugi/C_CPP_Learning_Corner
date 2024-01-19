#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;
int a[10001][10001];

struct List
{
    int first, second, weighting;
};

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    freopen("input.inp", "r", stdin);
    freopen("output.ans", "w", stdout);
    vector<List> edge;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] != 0 && i < j)
            {
                edge.push_back({i, j, a[i][j]});
            }
        }
    }


    for (auto x : edge)
    {
        cout << x.first << " " << x.second << " " << x.weighting << endl;
    }

    return 0;
}