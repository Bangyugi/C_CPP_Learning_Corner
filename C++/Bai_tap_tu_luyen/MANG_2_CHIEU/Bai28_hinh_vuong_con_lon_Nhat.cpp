#include <bits/stdc++.h>
using namespace std;

int a[1000][1000];

int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    long long _max = 0;
    long long sum = 0;
    for (int i = 2; i <= n - 1; i++)
    {
        for (int j = 2; j <= n - 1; j++)
        {
            sum = a[i][j];
            for (int k = 0; k < 8; k++)
            {
                int i1 = i + dx[k];
                int j1 = j + dy[k];
                sum += a[i1][j1];
            }
            _max = max(_max, sum);
        }
    }
    cout << _max;   
}