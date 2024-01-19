#include <bits/stdc++.h>
using namespace std;

int X[1005];
int visited[1005];
int cost = 0;
int ans = INT_MAX;
int c[1005][1005];
int Min_value = INT_MAX;

void Try(int i, int n)
{
    for (int j = 1; j <= n; j++)
    {
        if (!visited[j])
        {
            X[i] = j;
            visited[j] = 1;
            cost += c[X[i - 1]][X[i]];
            if (i == n)
            {
                ans = min(ans, cost + c[X[n]][1]);
            }
            else if (cost + (n - i + 1) * Min_value < ans)
            {
                Try(i + 1, n);
            }
            visited[j] = 0;
            cost -= c[X[i - 1]][X[i]];
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
            if (c[i][j] != 0)
                Min_value = min(Min_value, c[i][j]);
        }
    }
    X[1] = 1;
    visited[1] = 1;
    Try(2, n);
    cout << ans;
}