#include <string>
#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <Wincon.h>
#include <conio.h>
#define _UNICODE

#include <tchar.h>
#include <wchar.h>

//source: https://stackoverflow.com/a/45576563

int main() {
	//hard code special char string
	std::string test = u8"Greek: αβγδ; German: Übergrößenträger";
	//wide char unspecified size
	wchar_t temp[] = L"ß";
	//wide char specified size
	wchar_t temp2[] = L"ß";
	//set the current output codepage to utf8
	SetConsoleOutputCP(CP_UTF8);
	//set the current input codepage to utf8
	SetConsoleCP(CP_UTF8);
	//output hard coded variables
	std::cout << "first string" << std::endl << test << std::endl;
	std::wcout << "temp hard coded" << std::endl << temp << std::endl;
	std::cout << "temp2 hard coded" << std::endl << temp2 << std::endl;
	//begin user input
	std::cout << "user input: " << std::endl;
	std::wcin >> temp;
	std::cin.get();
	//output with out function call the user input
	//this seems not to output
	std::wcout << "this is the user input: " << std::endl << temp << std::endl;
	//this is outputting
	std::cout << "this is non wide cout of wide temp " << std::endl << temp << std::endl;
	//call the functions to change encoding
	int bufferSize = WideCharToMultiByte(CP_UTF8, 0, temp, -1, NULL, 0, NULL, NULL);
	char* m = new char[bufferSize]; 
	WideCharToMultiByte(CP_UTF8, 0, temp, -1, m, bufferSize, NULL, NULL);
	//output the changed encoding of temp
	std::wcout << "wide cout m after encoding change: " << std::endl << m << std::endl;
	std::cout << "non wide cout m after encoding change: " << std::endl << m << std::endl;
	std::cout << std::endl << std::endl;
	std::wprintf(L"%S", m); 
	std::cin.get();
}
