#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
vector<int> t;
int sum = 0;
// int X[10001];

void Try(int i, int a[], int n, int x, int pos)
{
    for (int j = pos; j <= n; j++)
    {
        sum += a[j];
        // X[i] = a[j];
        t.push_back(a[j]);
        if (sum == x)
        {
            v.push_back(t);
        }
        else
        {
            if (sum < x)
                Try(i + 1, a, n, x, j);
        }
        sum -= a[j];
        t.pop_back();
        // X[i] = 0;
    }
}

int main()
{
    int n, x;
    cin >> n >> x;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    Try(1, a, n, x, 1);
    if (v.empty())
    {
        cout << -1 << endl;
    }
    else
    {
        sort(v.begin(), v.end());
        cout << v.size() << endl;
        for (auto x : v)
        {
            cout << "{" << x[0];
            for (int i = 1; i < x.size(); i++)
            {
                cout << " " << x[i];
            }
            cout << "}";
            cout << endl;
        }
    }
}