#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
// vector<int> t;
int used[1001];
int x[11];

void Try(int i, int n)
{
    for (int j = 1; j <= n; j++)
    {
        if (!used[j] && abs(j - x[i - 1]) != 1)
        {
            x[i] = j;
            used[j] = 1;
            if (i == n)
            {
                vector<int> temp(x + 1, x + n + 1);
                v.push_back(temp);
            }
            else
            {
                Try(i + 1, n);
            }
            x[i] = 0;
            used[j] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    x[0] = INT_MAX;
    Try(1, n);
    sort(v.begin(), v.end());
    for (auto x : v)
    {
        for (auto z : x)
        {
            cout << z;
        }
        cout << endl;
    }
}