#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, q, r, l;
    cin >> n >> k >> q;
    vector<long long> pos(200001);
    vector<long long> D;

    while (n--)
    {
        cin >> l >> r;
        pos[l] += 1;
        pos[r + 1] -= 1;
    }
    
    for (int i = 1; i < 200001; i++)
    {
        pos[i] += pos[i - 1];
    }
    for (int i = 0; i < 200001; i++)
    {
        if (pos[i] >= k)
        {
            pos[i] = 1;
        }
        else
        {
            pos[i] = 0;
        }
    }
    for (int i = 1; i < 200001; i++)
    {
        pos[i] += pos[i - 1];
    }

    // for (int i = 1; i < 10; i++)
    // {
    //     cout << pos[i] << " ";
    // }
    // cout << endl;
    while (q--)
    {
        cin >> l >> r;
        cout << pos[r] - pos[l - 1] << endl;
    }
}