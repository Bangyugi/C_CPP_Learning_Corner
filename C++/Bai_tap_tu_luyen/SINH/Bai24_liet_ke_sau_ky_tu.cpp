#include <bits/stdc++.h>
using namespace std;

void sinh(int n, int k, int a[], bool &final)
{
    int i = k - 1;
    while (i >= 0 && a[i] == n)
    {
        i--;
    }
    if (i == -1)
    {
        final = true;
    }
    else
    {
        a[i]++;
        for (int j = i + 1; j < k; j++)
        {
            a[j] = 0;
        }
    }
}

int main()
{
    char c;
    int k;
    cin >> c >> k;
    vector<char> v;
    for (int i = 'A'; i <= c; i++)
    {
        v.push_back(char(i));
    }
    int a[k];
    int n = v.size() - 1;
    for (int i = 0; i < k; i++)
    {
        a[i] = 0;
    }
    bool final = false;
    while (!final)
    {
        for (int i = 0; i < k; i++)
        {
            cout << v[a[i]];
        }
        cout << endl;
        sinh(n, k, a, final);
    }

}