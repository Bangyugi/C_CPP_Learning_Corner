#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int last_val = -1;
    int first_val = -1;
    bool check = false;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x && check == false)
        {
            first_val = i + 1;
            check = true;
        }
        if (a[i] == x && check == true)
        {
            last_val = i + 1;
        }
    }
    cout << first_val << " " << last_val;
}