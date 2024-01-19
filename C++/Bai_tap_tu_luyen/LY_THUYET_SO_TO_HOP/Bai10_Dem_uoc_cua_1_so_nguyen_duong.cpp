#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    int p, e;
    long long cnt = 1;
    while (n--)
    {
        cin >> p >> e;
        cnt *= (e + 1) % 1000000007;
        cnt %= 1000000007;
    }
    cout << cnt;
}