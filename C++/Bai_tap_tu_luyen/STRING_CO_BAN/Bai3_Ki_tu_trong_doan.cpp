#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    long long sum = 0;
    for (int i = 0; i < s.size();i++)
    {
        if(isdigit(s[i]))
        {
            sum =sum+ s[i] - '0';
        }
    }
    cout << sum;
}