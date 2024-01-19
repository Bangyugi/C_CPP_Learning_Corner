#include <bits/stdc++.h>
using namespace std;
int final = 0;

void sinh(char s[], int n)
{
    int i = n - 1;
    while (i >= 0 && s[i] == 'A')
    {
        s[i] = 'B';
        i--;
    }
    if (i == -1)
        final = 1;
    else
        s[i] = 'A';
}

int main()
{
    int n;
    cin >> n;
    char s[n];
    for (int i = 0; i < n; i++)
    {
        s[i] = 'B';
    }
    while (final == 0)
    {
        for (int i = 0; i < n; i++)
        {
            cout << s[i];
        }
        cout << endl;
        sinh(s, n);
    }
}