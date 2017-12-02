// crt_setmodeunicode.c  
// This program uses _setmode to change  
// stdout to Unicode. Cyrillic and Ideographic  
// characters will appear on the console (if  
// your console font supports those character sets).  

//source: https://blogs.msmvps.com/gdicanio/2017/08/22/printing-utf-8-text-to-the-windows-console/
  
#include <fcntl.h>  
#include <io.h>  
#include <stdio.h>  
  
int main(void) {  
    //_setmode(_fileno(stdout), _O_U16TEXT);  
    //_O_U16TEXT would not work correct is below
    //source: https://stackoverflow.com/questions/8871540/o-wtext-o-u16text-o-u8text-are-these-modes-possible-in-mingw-compiler-ar
    _setmode(_fileno(stdout), 0x00020000);  
    wprintf(L"\x043a\x043e\x0448\x043a\x0430 \x65e5\x672c\x56fd\n");  
    getchar();
    return 0;  
}  
