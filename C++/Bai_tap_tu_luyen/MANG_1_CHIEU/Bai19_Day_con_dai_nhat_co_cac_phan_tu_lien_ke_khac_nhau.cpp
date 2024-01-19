#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    int cnt = 1;
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int index;
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[i - 1])
        {
            cnt++;
        }
        else
            cnt = 1;
        if (cnt >= ans)
        {
            ans = cnt;
            index = i;
        }
    }
    cout << ans << endl;
    for (int i = index - ans + 1; i <= index; i++)
    {
        cout << a[i] << " ";
    }
}