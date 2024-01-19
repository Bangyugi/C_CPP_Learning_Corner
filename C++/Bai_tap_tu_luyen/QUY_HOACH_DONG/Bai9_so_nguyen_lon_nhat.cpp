#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    string number1, number2;
    cin >> number1 >> number2;
    int dp[10] = {0};
    for (int i = 0; i < (int)number1.size(); i++)
    {
        if (dp[number1[i] - '0'] == 0)
            dp[number1[i] - '0']++;
    }
    for (int i = 0; i < (int)number2.size(); i++)
    {
        if (dp[number2[i] - '0'] == 1)
            dp[number2[i] - '0']++;
    }
    int cnt = 0;
    for (int i = 0; i < 10; i++)
    {
        if (dp[i] == 2)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}