#include <iostream>
#include <string>
#include <sstream>

void convertToASCII(std::string letter) {
        std::stringstream ss;
        ss << std::hex << letter;
        std::string res = ss.str();
        std::cout << res;
    /* for (int i = 0; i < letter.length(); i++) {
        
        // char x = ;
        // std::cout << int(x) << std::endl;
    } */
}

/* int main() {
    // std::cout << "Hello, ф or \u0444!\n";
    //std::cout << "\u006b\u003f\u00da \x61\n";
    std::string msg = "\xE0\xA4\xAE\xE0\xA4\xB9\xE0\xA4\xB8\xE0\xA5\x81\xE0\xA4\xB8";
    //std::cout << msg;
    std::stringstream ss;
    ss <<"pussy 123\n";
    std::cout << ss.str();
    
    std::string test1 = "fuck";
    convertToASCII(test1);
    std::cout << test1 << '\n';
} */
// https://www.tutorialspoint.com/convert-a-string-to-hexadecimal-ascii-values-in-cplusplus
#include <stdio.h>
#include <string.h>

void convert_hexa(char* input, char* output) {
    int loop = 0;
    int i = 0;
    while (input[loop] != '\0') {
        sprintf((char*)(output+i),"%02X", input[loop]);
        loop += 1;
        i += 2;
    }
    output[i++] = '\0';
}
int main() {
    char ascii_str[] = "wasd`";
    int len = strlen(ascii_str);
    char hex_str[(len*2)+1];
    convert_hexa(ascii_str, hex_str);
    printf("ASCII: %s\n", ascii_str);
    printf("Hexadecimal: %s\n", hex_str);
    return 0;
}

/*
up - \x75\x70
down - \x64\x6f\x77\x6e
left - \x6c\x65\x66\x74
right - \x72\x69\x67\x68\x74
unknown direction - \x75\x6e\x6b\x6e\x6f\x77\x6e\x20\x64\x69\x72\x65\x63\x74\x69\x6f\x6e
wasd` - \x77\x61\x73\x64\x60
Unsupported direction was passed! - \x55\x6e\x73\x75\x70\x70\x6f\x72\x74\x65\x64\x20\x64\x69\x72\x65\x63\x74\x69\x6f\x6e\x20\x77\x61\x73\x20\x70\x61\x73\x73\x65\x64\x21
There is no empty tile in the board! - \x54\x68\x65\x72\x65\x20\x69\x73\x20\x6e\x6f\x20\x65\x6d\x70\x74\x79\x20\x74\x69\x6c\x65\x20\x69\x6e\x20\x74\x68\x65\x20\x62\x6f\x61\x72\x64\x21
Enter a command:  - \x45\x6e\x74\x65\x72\x20\x61\x20\x63\x6f\x6d\x6d\x61\x6e\x64\x3a\x20
\n\nBye!\n\n - \x0a\x0a\x42\x79\x65\x21\x0a\x0a
\n\nYou won!\n\n - \x0a\x0a\x59\x6f\x75\x20\x77\x6f\x6e\x21\x0a\x0a
*/