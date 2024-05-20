#include <iostream>
#include <io.h>
#include <fcntl.h>
using namespace std;

int main()
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    wcout << L"Tiếng Việt có dấu" << endl;
    wstring test;
    wcout << L"Hãy nhập vào một chuỗi ký tự:" << endl;
    // wcin >> test;
    getline(wcin, test);
    wcout << L"Chuỗi ký tự mà bạn vừa mới nhập:" << endl;
    wcout << test << endl;
    for (int i = 0; i < (int)test.size(); i++)
    {
        wcout << test[i] << " : " <<wint_t(test[i])  << "\n";
    }

    // for (int i = 0; i < 300; i++)
    // {
    //     wcout << i << " : " << wchar_t(i) << "\n";
    // }
    return 0;
}