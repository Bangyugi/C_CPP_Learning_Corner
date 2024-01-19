#include <bits/stdc++.h>
using namespace std;

int n;
int a[101];
int k;
vector<vector<int>> v;
vector<int> temp;
int X[101];
int sum = 0;

void Backtrack(int i, int n, int k, int pos)
{
    for (int j = pos; j <= n; j++)
    {
        temp.push_back(a[j]);
        sum += a[j];
        if (sum == k)
        {
            v.push_back(temp);
        }
        else
        {
            Backtrack(i + 1, n, k, j + 1);
        }
        sum -= a[j];
        temp.pop_back();
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    Backtrack(1, n, k, 1);
    if (v.empty())
    {
        cout << "-1";
    }
    else
    {
        sort(v.begin(), v.end());
        for (auto x : v)
        {
            cout << "[" << x[0];
            for (int i = 1; i < x.size(); i++)
            {
                cout << " " << x[i];
            }
            cout << "]" << endl;
        }
    }
}