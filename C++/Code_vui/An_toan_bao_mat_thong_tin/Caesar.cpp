#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

char alphaUpperTable[26];
char alphaLowerTable[26];

string encrypt(string s, ll k)
{
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (isalpha(s[i]))
        {
            if (isupper(s[i]))
            {
                ll index = ((s[i] - 'A' + k) % 26);
                s[i] = alphaUpperTable[index];
            }
            else
            {
                ll index = ((s[i] - 'a' + k) % 26);
                s[i] = alphaLowerTable[index];
            }
        }
    }
    return s;
}

string decrypt(string s, ll k)
{
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (isalpha(s[i]))
        {
            if (isupper(s[i]))
            {
                ll index = (s[i] - 'A' - k) % 26;
                if (index < 0)
                {
                    index += 26;
                }
                s[i] = alphaUpperTable[index];
            }
            else
            {
                ll index = (s[i] - 'a' - k) % 26;
                if (index < 0)
                {
                    index += 26;
                }
                s[i] = alphaLowerTable[index];
            }
        }
    }
    return s;
}

int main()
{

    string s;
    ll k;
    srand(time(NULL));
    cout << "Nhap van ban can ma hoa: ";
    getline(cin, s);
    cout << s;
    k = rand() % 20 + 1;
    cout << "\nKhoa k la: " << k;
    for (int i = 0; i < 26; i++)
    {
        alphaUpperTable[i] = i + 'A';
    }
    for (int i = 0; i < 26; i++)
    {
        alphaLowerTable[i] = i + 'a';
    }
    string cipherText = encrypt(s, k);
    string plainText = decrypt(cipherText, k);
    cout << "\nVan ban giai ma la: " << cipherText;
    cout << "\nVan ban sau khi giai ma la: " << plainText;
    return 0;
}