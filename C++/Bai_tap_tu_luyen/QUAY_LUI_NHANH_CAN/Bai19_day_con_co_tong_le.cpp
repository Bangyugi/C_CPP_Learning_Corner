#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>> v;
vector<int> temp;
ll tong = 0;

void Try(int i, int n, ll a[], int pos)
{
    for (int j = pos; j <= n; j++)
    {
        temp.push_back(a[j]);
        tong += a[j];
        if (tong % 2 == 1)
        {
            v.push_back(temp);
        }
        Try(i + 1, n, a, j + 1);
        temp.pop_back();
        tong -= a[j];
    }
}

int main()
{
    int n;
    cin >> n;
    ll a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    Try(1, n, a, 1);
    if (v.empty())
    {
        cout << "NOT FOUND";
    }
    else
    {
        sort(v.begin(), v.end());
        for (auto x : v)
        {
            for (auto z : x)
            {
                cout << z << " ";
            }
            cout << endl;
        }
    }
    return 0;
}