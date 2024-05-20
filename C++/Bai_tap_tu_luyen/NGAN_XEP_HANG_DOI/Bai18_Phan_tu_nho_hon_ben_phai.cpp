#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

void solve(vector<long long> arr, int n)
{
    vector<long long> res;
    stack<long long> firstRightGreater;
    stack<long long> firstRightSmaller;
    for (int i = n - 1; i >= 0; i--)
    {
        if (firstRightGreater.empty())
        {
            firstRightGreater.push(arr[i]);
            res.push_back(-1);
            if (i != n - 1)
            {
                firstRightSmaller.push(arr[i + 1]);
            }
        }
        else if (arr[i] >= firstRightGreater.top())
        {
            while (!firstRightGreater.empty() && arr[i] >= firstRightGreater.top())
            {
                firstRightGreater.pop();
            }
            if (firstRightGreater.empty())
            {
                firstRightGreater.push(arr[i]);
                res.push_back(-1);
                if (i != n - 1)
                {
                    firstRightSmaller.push(arr[i + 1]);
                }
            }
            else
            {
                if (firstRightGreater.top() <= firstRightSmaller.top())
                {
                    while (!firstRightSmaller.empty() && firstRightGreater.top() <= firstRightSmaller.top())
                    {
                        firstRightSmaller.pop();
                    }
                    if (firstRightSmaller.empty())
                    {
                        res.push_back(-1);
                    }
                    else
                    {
                        res.push_back(firstRightSmaller.top());
                    }
                }
                else
                {
                    res.push_back(firstRightSmaller.top());
                }
                firstRightGreater.push(arr[i]);
                if (i != n - 1)
                {
                    firstRightSmaller.push(arr[i + 1]);
                }
            }
        }
        else
        {
            if (firstRightGreater.top() <= firstRightSmaller.top())
            {
                while (!firstRightSmaller.empty() && firstRightGreater.top() <= firstRightSmaller.top())
                {
                    firstRightSmaller.pop();
                }
                if (firstRightSmaller.empty())
                {
                    res.push_back(-1);
                }
                else
                {
                    res.push_back(firstRightSmaller.top());
                }
            }
            else
            {
                res.push_back(firstRightSmaller.top());
            }
            firstRightGreater.push(arr[i]);
            if (i != n - 1)
            {
                firstRightSmaller.push(arr[i + 1]);
            }
        }
    }
    reverse(res.begin(), res.end());
    for (auto x : res)
    {
        cout << x << " ";
    }
}

int main()
{

    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    solve(arr, n);
    return 0;
}