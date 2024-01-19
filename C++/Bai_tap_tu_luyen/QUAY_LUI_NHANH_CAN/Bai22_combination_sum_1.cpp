#include <bits/stdc++.h>
using namespace std;

int sum = 0;
vector<vector<int>> v;
vector<int> t;

void Try(int i, int n, int k, int pos)
{
    for (int j = pos; j <= 9; j++)
    {
        t.push_back(j);
        sum += j;
        if (i == k)
        {
            if (sum == n)
            {
                v.push_back(t);
            }
        }
        else if (sum < n)
        {
            Try(i + 1, n, k, j + 1);
        }
        t.pop_back();
        sum -= j;
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    Try(1, n, k, 1);
    if (v.empty())
    {
        cout << "NOT FOUND" << endl;
    }
    else
    {
        sort(v.begin(), v.end());
        for (auto x : v)
        {
            cout << x[0];
            for (int i = 1; i < k; i++)
            {
                cout << " + " << x[i];
            }
            cout << endl;
        }
    }
}