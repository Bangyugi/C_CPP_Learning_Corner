#include <bits/stdc++.h>
using namespace std;

vector<string> v;
// vector<int> temp;
int x[1001];

void Try(int i, int a[], int n, int pos)
{
    for (int j = pos; j <= n; j++)
    {
        if (a[j] > x[i - 1])
        {
            x[i] = a[j];
            if (i >= 2)
            {
                string temp;
                for (int t = 1; t <= i; t++)
                {
                    temp = temp + to_string(x[t]) + " ";
                }
                v.push_back(temp);
            }
            Try(i + 1, a, n, j + 1);
            x[i] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    Try(1, a, n, 1);
    sort(v.begin(), v.end());
    for (auto x : v)
    {
        cout << x << endl;
    }
}