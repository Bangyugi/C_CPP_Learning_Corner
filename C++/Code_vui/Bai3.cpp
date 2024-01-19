#include <bits/stdc++.h>
using namespace std;
int main()
{
    unsigned int x, n;
    cin >> x >> n;
    double s = 0, v = 1;
    for (int i = 1; i <= n; i++)
    {
        v *= i;
        s += ((double)pow(x, 2 * n) / (2 * n) * v);
    }
    cout << s;

    return 0;
}
