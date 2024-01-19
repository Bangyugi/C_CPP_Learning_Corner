#include <bits/stdc++.h>
using namespace std;

bool check = false;

void lietKe(string v[], int n)
{
    int i = n - 1;
    while (i >= 1 && v[i] > v[i + 1])
    {
        i--;
    }
    if (i == 0)
    {
        check = true;
    }
    else
    {
        int j = n;
        while (v[i] > v[j])
        {
            j--;
        }
        swap(v[i], v[j]);
        sort(v + i + 1, v + n + 1);
    }
}

int main()
{
    int n;
    cin >> n;
    string name[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> name[i];
    }
    sort(name + 1, name + n + 1);
    while (!check)
    {

        for (int i = 1; i <= n; i++)
        {
            cout << name[i] << " ";
        }
        cout << endl;
        lietKe(name, n);
    }
}