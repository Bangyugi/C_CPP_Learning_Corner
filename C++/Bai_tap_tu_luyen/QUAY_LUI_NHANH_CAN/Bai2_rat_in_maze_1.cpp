#include <bits/stdc++.h>
using namespace std;

int X[14][14];
string Duongdi;
vector<string> v;
int dx[2] = {0, 1};
int dy[2] = {1, 0};

void BackTrack(int i, int j, int n)
{
    for (int k = 0; k < 2; k++)
    {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if (X[i1][j1] == 1 && i1 <= n && j1 <= n)
        {
            if (k == 0)
            {
                Duongdi.push_back('R');
            }
            else
            {
                Duongdi.push_back('D');
            }
            if (i1 == n && j1 == n)
            {
                v.push_back(Duongdi);
            }
            else
            {
                BackTrack(i1, j1, n);
            }
            Duongdi.pop_back();
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
            cin >> X[i][j];
        }
    }
    BackTrack(1, 1, n);
    if (v.empty())
    {
        cout << "-1";
    }
    else
    {
        sort(v.begin(), v.end());
        for (auto x : v)
        {
            cout << x << "\n";
        }
    }
}