#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <string>
int main()
{
    _setmode(_fileno(stdin), _O_WTEXT);
    _setmode(_fileno(stdout), _O_WTEXT);
    std::wcout << L"Tiếng Việt có dấu" << std::endl;
    wchar_t test[256] = { 0 };
    
    std::wcin >> test;
    return 0;
}