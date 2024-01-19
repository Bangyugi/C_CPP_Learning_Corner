#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    ll s, d;
    cin >> s >> d;
    if (s >= 9 * d)
    {
        cout << -1;
    }
    else
    {
        s--;
        ll sum = pow(10, --d);
        int i = 0;
        while (s >= 10)
        {
            s -= 9;
            sum += 9 * pow(10, i);
            i++;
        }
        sum += s * pow(10, i);
        cout << sum;
    }
    return 0;
}