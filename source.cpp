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
	SetConsoleOutputCP(CP_UTF8);
	std::cout << test << std::endl;
}
