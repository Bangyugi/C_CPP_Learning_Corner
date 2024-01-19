#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    int demSoChan = 0, demSoLe = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] % 2 == 0)
        {
            demSoChan++;
        }
        else
        {
            demSoLe++;
        }
    }
    if (demSoChan % 2 == 0 && demSoLe % 2 == 0)
    {
        cout << "YES";
    }
    else if (demSoChan%2==1 && demSoLe%2==1)
    {
        sort(a,a+n);
        for (int i = 1; i < n; i++)
        {
            if (abs(a[i]-a[i-1])==1)
            {
                cout<<"YES";
                return 0;
            }
        }
        cout<<"NO";
    }
    else
    {
        cout<<"NO";
    }

    return 0;
}