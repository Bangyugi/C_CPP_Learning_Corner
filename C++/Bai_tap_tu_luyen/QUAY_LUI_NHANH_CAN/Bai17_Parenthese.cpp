#include <bits/stdc++.h>
#define ll long long
using namespace std;
char d[6] = {'(', ')', '[', ']', '{', '}'};

// bool check(string s)
// {
//     stack<char> t;
//     for (int i = 0; i < s.size(); i++)
//     {
//         if (s[i] == '(' || s[i] == '[' || s[i] == '{')
//         {
//             t.push(s[i]);
//         }
//         else if (t.empty())
//         {
//             return false;
//         }
//         else if (t.top() == '(' && s[i] == ')')
//         {
//             t.pop();
//         }
//         else if (t.top() == '[' && s[i] == ']')
//         {
//             t.pop();
//         }
//         else if (t.top() == '{' && s[i] == '}')
//         {
//             t.pop();
//         }
//         else
//         {
//             return false;
//         }
//     }
//     if (t.empty())
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

stack<char> k;

bool check2(char c)
{
    if (c == '(' || c == '[' || c == '{')
    {
        k.push(c);
    }
    else if (k.empty())
    {
        return false;
    }
    else if (k.top() == '(' && c == ')')
    {
        k.pop();
    }
    else if (k.top() == '[' && c == ']')
    {
        k.pop();
    }
    else if (k.top() == '{' && c == '}')
    {
        k.pop();
    }
    else
    {
        return false;
    }
    return true;
}

void Try(int i, int n, vector<string> &v, string &t)
{

    for (int j = 0; j < 6; j++)
    {
        t.push_back(d[j]);
        if (i == n)
        {
            if (check(t))
                v.push_back(t);
        }
        else if (check2(d[j]))
        {
            Try(i + 1, n, v, t);
        }
        t.pop_back();
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string> v;
    string t;
    Try(1, n, v, t);
    sort(v.begin(), v.end());
    for (auto x : v)
    {
        cout << x << " ";
    }
    return 0;
}