#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long cnt = 0;
    vector<int> v = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    for (int i = 0; i < v.size(); i++)
    {
        cnt += n / v[i];
        n %= v[i];
    }
    cout << cnt;
}