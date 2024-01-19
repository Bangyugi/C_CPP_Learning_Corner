#include <bits/stdc++.h>
using namespace std;
int main()
{
    unsigned int x, n;
    cin >> x >> n;
    double gt = 1, sum = 0;
    for (int i = n; i >= 1; i--)
    {
        gt = gt * i;
    }
    for (int i = 1; i <= n; i++)
    {
        sum += (pow(x, 2 * n) / (2 * n) * gt);
        cout << sum;
    }
    return 0;
}
