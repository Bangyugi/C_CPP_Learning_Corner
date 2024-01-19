#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < (1 << n); i++)
    {
        cout << i << " = ";
        for (int bit = n - 1; bit >= 0; bit--)
        {
            if (i & (1 << bit))
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
        }
        cout << endl;
    }
}