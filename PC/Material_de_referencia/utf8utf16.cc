#include <iostream>
#include <codecvt>
#include <string>
#include <locale>

int main(){

// UTF-8
// Default for g++ in linux systems
const char s1[] {"Halag\u00fce\u00f1o"};
const char s2[] {"Halagüeño"};
//const char8_t s3[] {u8"Halag\u00fce\u00f1o"};
//const char8_t s4[] {u8"Halag\u00fce\u00f1o\U0001D11E"};


//Streaming utf8 chars
std::cout<<"Literal de cadena con universal character names: "<<s1<<std::endl;
std::cout<<"Literal de cadena sin universal character names: "<<s2<<std::endl;
//std::cout<<"Literal de cadena con universal character names UTF8 convertido stream de bytes: "<<reinterpret_cast<const char*>(s3)<<std::endl;
//std::cout<<"Literal de cadena con universal character names UTF8 convertido a stream de bytes: "<<reinterpret_cast<const char*>(s4)<<std::endl;


// UTF-16

const wchar_t s5[] {L"Halag\u00fce\u00f1o\U0001D11E"};

const char16_t s6[] {u"Halag\u00fce\u00f1o\U0001D11E"};
//Streaming out wide chars
std::wcout<<s5<<std::endl;
std::cout<<reinterpret_cast<const char*>(s6)<<std::endl;

std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> converter;
std::u16string s7 {u"Halag\u00fce\u00f1o\U0001D11E"};
std::string s8 = converter.to_bytes(s7);
std::cout<<"Literal cadena utf-16 y u16string convertido a utf-8: "<<s8<<std::endl;
return 0;
}