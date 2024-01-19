#include <bits/stdc++.h>
using namespace std;

void reverse_(string s)
{
    for (int i = s.size() - 1; i >= 0; i--)
    {
        cout << s[i];
    }
    cout << endl;
}
void inThuong(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        s[i] = tolower(s[i]);
        cout << s[i];
    }
    cout << endl;
}

void inHoa(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        s[i] = toupper(s[i]);
        cout << s[i];
    }
    cout << endl;
}

int main()
{
    string s;
    cin >> s;
    reverse_(s);
    inThuong(s);
    inHoa(s);
}