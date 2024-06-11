// https://blog.websandbag.com/entry/2022/10/01/162826

#include <iostream>
#include <string>

int main() {
    // const std::char8_t[] abc = u8"日本語";
    std::string jp {u8"日本語"};
    std::cout << jp << std::endl;
    std::cout << "日本語" << std::endl;
    std::cout << "\u0065" << std::endl;

    std::u16string b(u"ハロー・ワールド");
    std::cout << b << std::endl;
    return 0;
}