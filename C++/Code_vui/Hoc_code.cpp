#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    ll cnt = 0;
    for (int i = 1; i < 18; i++)
    {
        for (int j = 2; j < 18; j++)
        {
            for (int k = 0; k <= 2; k++)
            {
                if (i + j + k < 18)
                {
                    cnt++;
                    cout << i << "+" << j << "+" << k << "=" << i + j + k << endl;
                }
            }
        }
    }
    cout << cnt;
    return 0;
}