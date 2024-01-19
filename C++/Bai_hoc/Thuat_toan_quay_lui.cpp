#include <bits/stdc++.h>
using namespace std;

int x[1000];
int n;

// void backtrack(int i)
// {
//     // đi thử xem X[i] có thể nhận những giá trị nào?
//     for (int j = 1; j <= n; j++)
//     {
//         x[i] = j;
//         if (i == n)
//         {
//             return res;
//         }
//         else
//         {
//             backtrack(i + 1);
//         }
//     }
// }


void backtrack(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        x[i] = j;
        if (i == n)
        {
            for (int k = 1; k <= n; k++)
            {
                cout << x[k];
            }
            cout << endl;
        }
        else
        {
            backtrack(i + 1);
        }
    }
}

int main()
{
    cin >> n;
    backtrack(1);
    
}