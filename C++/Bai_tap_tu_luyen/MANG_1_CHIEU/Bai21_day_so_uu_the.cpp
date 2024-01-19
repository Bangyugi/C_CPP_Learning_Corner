#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int cntle = 0;
    int cntchan = 0;
    while (cin >> n)
    {
        if (n % 2 == 0)
        {
            cntchan++;
        }
        else
        {
            cntle++;
        }
    }
    int temp = cntchan + cntle;
    if ((cntchan > cntle && temp % 2 == 0) || (cntchan < cntle && temp % 2 != 0))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}