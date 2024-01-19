#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    long long a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long sum = 0;
    long long l = 0;
    long long ans = 0;
    int index = 0;
    for (int i = 0; i < k; i++)
    {
        sum += a[i];
    }
    ans = max(sum, ans);
    index = 0;
    for (int i = k; i < n; i++)
    {

        sum += a[i];
        sum -= a[l++];
        if (sum > ans)
        {
            ans = sum;
            index = l;
        }
    }
    cout << ans << "\n";
    for (int i = index; i < index + k; i++)
    {
        cout << a[i] << " ";
    }
}