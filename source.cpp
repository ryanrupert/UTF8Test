#include <iostream>
#include <cstdio>
#include <sstream>

#include <Windows.h>

//source: https://stackoverflow.com/questions/45575863/how-to-print-utf-8-strings-to-stdcout-on-windows

class MBuf: public std::stringbuf {
public:
    int sync() {
        fputs( str().c_str(), stdout );
        str( "" );
        return 0;
    }
};

int main() {
    SetConsoleOutputCP( CP_UTF8 );
    setvbuf( stdout, nullptr, _IONBF, 0 );
    MBuf buf;
    std::cout.rdbuf( &buf );
    std::cout << u8"Greek: αβγδ\n" << std::flush;
} 
