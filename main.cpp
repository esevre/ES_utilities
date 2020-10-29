
#include <iostream>
#include <iomanip>

#include "ES/file/read.hpp"


template <class Type>
struct CharConverter
{
    using CharPtr = char *;
    using ConstCharPtr = const CharPtr;

    static CharPtr convert(Type &var) { return (CharPtr) &var; }
    static ConstCharPtr convert(const Type &var) { return (CharPtr) &var; }
    static std::size_t TypeSize() { return sizeof(Type); }
};

struct HexCharStruct {
    unsigned char c;
    HexCharStruct(unsigned char &c) : c(c) {}
};
inline std::ostream & operator<<(std::ostream &os, const HexCharStruct& hs)
{
    return (os << std::hex << (int)hs.c);
}
inline HexCharStruct hex(unsigned char c) {
    return HexCharStruct(c);
}

template <class Type>
void hex_print(const Type &var)
{
    auto size = CharConverter<Type>::TypeSize();
    const auto cptr = CharConverter<Type>::convert(var);

    for (int i = size-1; i >= 0; --i){
        unsigned char c = cptr[i];
        std::cout  << std::setw(2) << std::setfill('0') << hex(c);
    }
    std::cout << std::endl;

}

int main(){
    int i = 1;
    // hex_print(i);
    for (i = 8; i < 400; i+=2){
        hex_print(i);
    }

}



