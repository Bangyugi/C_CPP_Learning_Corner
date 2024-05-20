#include <bits/stdc++.h>
#include <io.h>
#include <fcntl.h>
#include <vector>
using namespace std;
vector<wchar_t> vietnameseAlphabet;

pair<wint_t, wint_t> keyGenerator()
{
    vector<int> coprime;
    for (int i = 1; i <= 26; i++)
    {
        if (__gcd(i, 7929) == 1)
        {
            coprime.push_back(i);
        }
    }
    wint_t a, b;
    a = coprime[rand() % (coprime.size() - 1) + 1];
    b = rand() % 26;
    while (a == b)
    {
        b = rand() % 26;
    }

    return {a, b};
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

wstring encrypt(wstring s, pair<wint_t, wint_t> key)
{
    for (wint_t i = 0; i < (wint_t)s.size(); i++)
    {
        s[i] = (key.first * (wint_t)s[i] + key.second) % 7929;
    }
    return s;
}

wstring decrypt(wstring s, pair<wint_t, wint_t> key)
{
    for (wint_t i = 0; i < (wint_t)s.size(); i++)
    {
        s[i] = (Extended_Euculid(key.first, 7929) * (((wint_t)s[i] - key.second) % 7929)) % 7929;
    }
    return s;
}

int main()
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    wcout << L"Nhập số testcase: ";
    wint_t t;
    wcin >> t;
    while (t--)
    {
        wcout << "\n ------------------------------- \n\n";
        wstring originalText = L"Bằng Trần Văn Đẹp Trai, ĐẠI HỌC CÔNG NGHIỆP HÀ NỘI";
        // wcout << L"Nhập vào văn bản cần mã hóa: ";
        // wcin >> originalText;
        // for (wint_t i = 0; i < (wint_t)originalText.size(); i++)
        // {
        //     wcout << originalText[i] << " : " << (wint_t)originalText[i] << endl;
        // }
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