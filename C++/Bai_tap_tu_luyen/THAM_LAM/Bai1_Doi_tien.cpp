#include <bits/stdc++.h>
using namespace std;

int d[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 9; i >= 0; i--)
    {
        if (n >= d[i])
        {
            sum += n / d[i];
            n %= d[i];
        }
    }
    cout << sum << endl;
}