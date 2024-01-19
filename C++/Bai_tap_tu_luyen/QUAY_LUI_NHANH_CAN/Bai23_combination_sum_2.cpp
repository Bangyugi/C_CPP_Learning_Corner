#include <bits/stdc++.h>
#define ll long long
using namespace std;

int isprime[1001];
int sum = 0;
vector<vector<int>> v;
vector<int> t;

void sang()
{
    for (int i = 2; i <= 1000; i++)
    {
        isprime[i] = 1;
    }
    for (int i = 1; i <= sqrt(1000); i++)
    {
        if (isprime[i])
        {
            for (int j = i * i; j <= 1000; j += i)
            {
                isprime[j] = 0;
            }
        }
    }
}

void Try(int i, int pos, int n, int k)
{
    for (int j = pos; j <= n; j++)
    {
        if (isprime[j])
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
                Try(i + 1, j + 1, n, k);
            }
            t.pop_back();
            sum -= j;
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    sang();
    Try(1, 1, n, k);
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
    return 0;
}