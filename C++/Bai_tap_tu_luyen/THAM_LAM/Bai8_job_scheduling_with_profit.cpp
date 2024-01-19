#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

struct Job
{
    int ID, Deadline, Profit;
};

bool cmp(Job a, Job b)
{
    if (a.Profit != b.Profit)
    {
        return a.Profit > b.Profit;
    }
    else
    {
        return a.Deadline > b.Deadline;
    }
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    int n;
    cin >> n;
    Job a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].ID >> a[i].Deadline >> a[i].Profit;
    }
    sort(a, a + n, cmp);
    ll ans = 0;
    int used[n] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = a[i].Deadline - 1; j >= 0; j--)
        {
            if (used[j] == 0)
            {
                ans += a[i].Profit;
                used[j] = 1;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}