#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    multiset<ll> se;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        se.insert(x);
    }

    ll sum = 0;
    ll ans = 0;
    while (se.size() >= 2)
    {
        auto day1 = se.begin();
        auto day2 = day1;
        day2++;
        sum = *day1 + *day2;
        se.erase(day1);
        se.erase(day2);
        se.insert(sum);
        ans += sum;
    }
    cout << ans;
    return 0;
}