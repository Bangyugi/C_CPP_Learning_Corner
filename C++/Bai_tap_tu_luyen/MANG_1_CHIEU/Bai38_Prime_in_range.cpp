#include <bits/stdc++.h>
using namespace std;

int prime[1000001];
int a[1000001];

void sang()
{
    for (int i = 2; i <= 1000001; i++)
    {
        prime[i] = 1;
    }
    for (int i = 2; i <= sqrt(1000001); i++)
    {
        if (prime[i] == 1)
        {
            for (int j = i * i; j <= 1000001; j+=i)
            {
                prime[j] = 0;
            }
        }
    }
    int dem = 0;
    for (int i = 0; i < 1000001; i++)
    {
        if (prime[i])
        {
            dem++;
        }
        a[i] = dem;
    }
}

int main()
{
    int n,l,r;
    cin >> n;
    sang();
    
        while (n--)
        {
            cin >> l >> r;
            cout << a[r] - a[l - 1] << endl;
        }
}