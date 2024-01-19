#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int cnt25 = 0;
    int cnt50 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 25)
        {
            cnt25++;
        }
        else if (a[i] == 50)
        {
            if (cnt25 == 0)
            {
                cout << "NO";
                return 0;
            }
            else
            {
                cnt25--;
                cnt50++;
            }
        }
        else if (a[i] == 100)
        {
            if (cnt50 == 0 || cnt25 == 0 || cnt25 < 3)
            {
                cout << "NO";
                return 0;
            }
            else if (cnt50 > 0 && cnt25 > 0)
            {
                cnt25--;
                cnt50--;
            }
            else if (cnt25 >= 3)
            {
                cnt25 -= 3;
            }
        }
    }
    cout << "YES";
}