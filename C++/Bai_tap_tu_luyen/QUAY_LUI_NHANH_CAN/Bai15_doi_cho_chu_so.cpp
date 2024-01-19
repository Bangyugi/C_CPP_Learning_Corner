#include <bits/stdc++.h>
#define ll long long
using namespace std;

string s;
// int k;
// int n;
// int a[100];
vector<ll> v;

void Try(int i, int pos, int n, int k, int a[])
{
    for (int j = 1; j <= n; j++)
    {
        if (i != j)
        {
            swap(a[i], a[j]);
            if (i == k)
            {
                string t;
                for (int i = 1; i <= n; i++)
                {
                    t.push_back((char)(a[i] + '0'));
                }
                v.push_back(stoll(t));
            }
            else if (i <= n)
            {
                Try(i + 1, j + 1, n, k, a);
            }
            swap(a[i], a[j]);
        }
    }
}

int main()
{
    int k;
    string s;
    cin >> k;
    cin >> s;
    int n = s.size();
    int a[100];
    for (int i = 1; i <= n; i++)
    {
        a[i] = s[i - 1] - '0';
    }
    Try(1, 1, n, k, a);
    sort(v.begin(), v.end(), greater<>());
    cout << v[0];

    return 0;
}