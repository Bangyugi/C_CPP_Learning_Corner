#include <bits/stdc++.h>
#define ll long long
using namespace std;

void maxSum(string &a, string &b)
{
    ll sum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '5')
        {
            a[i] = '6';
        }
    }
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] == '5')
        {
            b[i] = '6';
        }
    }
    sum = stoll(a) + stoll(b);
    cout << sum << " ";
}

void minSum(string &a, string &b)
{
    ll sum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '6')
        {
            a[i] = '5';
        }
    }
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] == '6')
        {
            b[i] = '5';
        }
    }
    sum = stoll(a) + stoll(b);
    cout << sum << " ";
}

int main()
{
    string a, b;
    cin >> a >> b;
    maxSum(a,b);
    minSum(a,b);
    return 0;
}