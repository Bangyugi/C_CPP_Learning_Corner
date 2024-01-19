#include <bits/stdc++.h>
#define ll long long
using namespace std;

int a[1005][1005];
int cot[1005];
int duongcheonguoc[1005];
int duongcheoxuoi[1005];

void Try(int i, int n)
{
    for (int j = 1; j <= n; j++)
    {
        if (cot[j] == 0 && duongcheoxuoi[j - i + n] == 0 && duongcheonguoc[i + j - 1] == 0)
        {
            a[i][j] = 1;
            cot[j] = duongcheoxuoi[j - i + n] = duongcheonguoc[i + j - 1] = 1;
            if (i == n)
            {
                for (int l = 1; l <= n; l++)
                {
                    for (int k = 1; k <= n; k++)
                    {
                        if (a[l][k])
                        {
                            cout << "Q";
                        }
                        else
                        {
                            cout << ".";
                        }
                    }
                    cout << endl;
                }
                cout << endl;
            }
            else
            {
                Try(i + 1, n);
            }
            cot[j] = duongcheoxuoi[j - i + n] = duongcheonguoc[i + j - 1] = 0;
            a[i][j] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    Try(1, n);
    return 0;
}