#include <bits/stdc++.h>
#define ll long long
using namespace std;

char a[1000][1000];
bool check = false;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int visited[1000][1000];
string t;

void solve1(int u, int v, int n, int m, string s)
{
    // visited[u][v] = 1;
    for (int k = 0; k < 4; k++)
    {
        int i1 = u + dx[k];
        int j1 = v + dy[k];
        if (!visited[i1][j1] && i1 <= n && j1 <= m && i1 >= 1 && j1 >= 1 && s.find(a[i1][j1]) != -1)
        {
            visited[i1][j1] = 1;
            t.push_back(a[i1][j1]);
            // cout << t << endl;
            if (t == s)
            {
                // cout << t << endl;
                check = true;
            }
            else
            {
                solve1(i1, j1, n, m, s);
            }
            t.pop_back();
            visited[i1][j1] = 0;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < m; j++)
        {
            a[i][j + 1] = temp[j];
        }
    }
    string s;
    // cin >> s;

    cin >> s;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j]==s[0])
            {
                t.push_back(a[i][j]);
                visited[i][j] = 1;
                solve1(i, j, n, m, s);
                t.pop_back();
                visited[i][j] = 0;
            }
        }
    }

    if (check)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
