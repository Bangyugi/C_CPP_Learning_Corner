#include <bits/stdc++.h>
#include <io.h>
#include <fcntl.h>
#include <vector>
using namespace std;

map<wchar_t, wint_t> vietnameseAlphabet;
int tableSize = 0;

void initAlphabetTable()
{
    wint_t index = 0;
    vietnameseAlphabet[' '] = index++;
    for (wint_t i = 65; i <= 89; i++)
    {
        vietnameseAlphabet[wchar_t(i)] = index++;
    }

    for (wint_t i = 97; i <= 121; i++)
    {
        vietnameseAlphabet[wchar_t(i)] = index++;
    }

    for (wint_t i = 192; i <= 432; i++)
    {
        vietnameseAlphabet[wchar_t(i)] = index++;
    }

    for (wint_t i = 7840; i <= 7929; i++)
    {
        vietnameseAlphabet[wchar_t(i)] = index++;
    }

    tableSize = vietnameseAlphabet.size();
}

pair<wint_t, wint_t> keyGenerator()
{
    vector<int> coprime;
    for (int i = 1; i <= 26; i++)
    {
        if (__gcd(i, tableSize) == 1)
        {
            coprime.push_back(i);
        }
    }
    wint_t a = coprime[rand() % coprime.size()];
    wint_t b = rand() % 25+1;
    while (b == a)
    {
        b = rand() % 25+1;
    }

    return {a, b};
}

wstring encrypt(wstring s, pair<wint_t, wint_t> k)
{
    for (wint_t i = 0; i < (wint_t)s.size(); i++)
    {
        auto it = vietnameseAlphabet.begin();
        advance(it, (k.first * vietnameseAlphabet[s[i]] + k.second) % tableSize);
        s[i] = it->first;
    }
    return s;
}

long long Extended_Euculid(long long a, long long b)
{
    long long r1 = a, r2 = b;
    long long x1 = 1, x2 = 0;
    long long y1 = 0, y2 = 1;

    while (r2 % r1 != 0)
    {
        long long r = r2 % r1;
        long long q = r2 / r1;
        long long x = x2 - q * x1;
        long long y = y2 - q * y1;
        r2 = r1;
        r1 = r;
        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;
    }
    if (x1 < 0)
    {
        return b + x1;
    }
    return x1;
}

wstring decrypt(wstring s, pair<wint_t, wint_t> k)
{
    for (wint_t i = 0; i < (wint_t)s.size(); i++)
    {
        auto temp = ((vietnameseAlphabet[s[i]] - k.second) % tableSize);
        if (temp < 0)
            temp += tableSize;
        auto it = vietnameseAlphabet.begin();
        advance(it, (Extended_Euculid(k.first, tableSize) * temp) % tableSize);
        s[i] = it->first;
    }
    return s;
}

int main()
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    initAlphabetTable();
    wcout << L"Nhập số testcase: ";
    wint_t t;
    wcin >> t;
    while (t--)
    {
        wcout << "\n ------------------------------- \n\n";
        wstring originalText = L"Encrypt and Decrypt ĐẠI HỌC CÔNG NGHIỆP HÀ NỘI by Trần Văn Bằng";
        pair<wint_t, wint_t> key = keyGenerator();
        wcout << L"Khóa K là: " << key.first << ", " << key.second << endl;
        wstring cipherText = encrypt(originalText, key);
        wcout << L"Văn bản sau khi mã hóa là: " << cipherText << endl;
        wstring plainText = decrypt(cipherText, key);
        wcout << L"Văn bản sau khi giải mã là: " << plainText << endl;
        if (plainText != originalText)
        {
            wcout << L"fail!!" << endl;
            return 0;
        }
    }
    return 0;
}
