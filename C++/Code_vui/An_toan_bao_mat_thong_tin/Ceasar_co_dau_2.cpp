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

wstring encrypt(wstring s, wint_t k)
{
    for (wint_t i = 0; i < (wint_t)s.size(); i++)
    {
        auto it = vietnameseAlphabet.begin();
        advance(it, (vietnameseAlphabet[s[i]] + k) % tableSize);
        s[i] = it->first;
    }
    return s;
}

wstring decrypt(wstring s, wint_t k)
{
    for (wint_t i = 0; i < (wint_t)s.size(); i++)
    {
        auto it = vietnameseAlphabet.begin();
        auto temp = (vietnameseAlphabet[s[i]] - k) % tableSize;
        if (temp < 0)
            temp += tableSize;
        advance(it, temp);
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
        wstring originalText = L"Trần Văn Bằng ĐẠI HỌC CÔNG NGHIỆP HÀ NỘI CNTT";
        wint_t k = rand() % 25 + 1;
        wcout << L"Khóa K là: " << k << endl;
        wstring cipherText = encrypt(originalText, k);
        wcout << L"Văn bản sau khi mã hóa là: " << cipherText << endl;
        wstring plainText = decrypt(cipherText, k);
        wcout << L"Văn bản sau khi giải mã là: " << plainText << endl;
        if (plainText != originalText)
        {
            wcout << L"fail!!" << endl;
            return 0;
        }
    }

    return 0;
}
