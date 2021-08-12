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

	wstring link = L"D:/Document/English/06_Vocabulary/VocaText/";
	vector<wstring> chooseNameFiles = { (L"[1] NewPhrase"),(L"[2] NewVoca"), (L"[8] VNU_NewSentence")};

	
	for (int k = 1; k < 36; k++) {
		wstring temp = L"Voca_";
		wstring number = to_wstring(k);
		if (k < 10)
			temp = temp + L"0" + number;
		else
			temp = temp + number;
		chooseNameFiles.push_back(temp);
	}
	while (1) {
		int flag = 0;
		wcout << L"Nhập từ bạn cần tìm: ";
		rewind(stdin);
		getline(wcin, wordSearching);
		for (int i = 0; i < chooseNameFiles.size(); i++) {
			wstring realLink = link + chooseNameFiles[i] + L".txt";
			wfstream fin(realLink);
			//if (!fin)
				//wcout << L"cann't open file "<<chooseNameFiles[i];
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
			wcout << L"Không tìm thấy!" << endl;
		wcout << endl;
	}
	return 0;
}