#include <string>
#include <iostream>
#include <Windows.h>
#include <Wincon.h>
#include <conio.h>
#define _UNICODE

#include <tchar.h>
#include <wchar.h>

//source: https://stackoverflow.com/a/45576563

int main() {
	std::string test = u8"Greek: αβγδ; German: Übergrößenträger";
	wchar_t temp[] = L"ß";
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	std::cout << test << std::endl;
	std::cout << "test input: " << std::endl;
	std::wcin >> temp;
	std::cin.get();
	std::wcout << temp << std::endl;
	std::wcout << temp << std::endl;
	int bufferSize = WideCharToMultiByte(CP_UTF8, 0, temp, -1, NULL, 0, NULL, NULL);
	char* m = new char[bufferSize]; 
	WideCharToMultiByte(CP_UTF8, 0, temp, -1, m, bufferSize, NULL, NULL);
	std::wcout << "input: " << temp << std::endl;
	std::cout << std::endl;
	std::cout << "input2: " << m << std::endl;
	std::cout << "fail" << std::endl;
	std::cout << "test: " << temp << std::endl;
	std::wprintf(L"%S", m); 
	std::cin.get();
}
