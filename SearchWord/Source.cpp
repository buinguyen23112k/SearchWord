#include <iostream>
#include <fcntl.h> //_O_WTEXT
#include <io.h>    //_setmode()
#include <stdio.h>
#include <string>
#include <locale>
#include <codecvt> //possible C++11?
#include <fstream>
#include <vector>
#include <iomanip>
#include <Windows.h>
#include <random>
#include <time.h>
#include <conio.h>
using namespace std;

int main()
{
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
	std::locale loc(std::locale(), new std::codecvt_utf8<wchar_t>);		// UTF-8
	wstring wordSearching;

	wstring link = L"D:/Document/English/Vocabulary/VocaText/";
	vector<wstring> chooseNameFiles = { (L"Voca_01"),(L"Voca_02"),(L"Voca_03"),(L"Voca_04"),(L"Voca_05"),(L"Voca_06"),(L"Voca_07"),(L"Voca_08"),(L"Voca_09"),(L"Voca_10"),(L"Voca_11"),(L"Voca_12"),(L"Voca_13"),(L"Voca_14"),(L"Voca_15"),(L"[1] NewPhrase"),(L"[2] NewVoca") };

	while (1) {
		int flag = 0;
		wcout << L"Nhập từ bạn cần tìm: ";
		rewind(stdin);
		wcin >> wordSearching;
		for (int i = 0; i < chooseNameFiles.size(); i++) {
			wstring realLink = link + chooseNameFiles[i] + L".txt";
			wfstream fin(realLink);
			if (!fin)
				wcout << L"cann't open file "<<chooseNameFiles[i];
			fin.imbue(loc);
			while (fin) {
				wstring eachWordInFile;
				rewind(stdin);
				getline(fin, eachWordInFile);
				if (eachWordInFile == L"end(file)")
					break;
				if (eachWordInFile.find(wordSearching) != wstring::npos) {		// tìm thấy trả về 0
					flag = 1;
					wcout <<"["<<chooseNameFiles[i]<<"] "<< eachWordInFile << "\n";
				}
			}
		}
		if (!flag)
			wcout << L"Không tìm thấy !" << endl;
		wcout << endl;
	}
	return 0;
}