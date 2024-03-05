#include <cassert>
#include <iostream>

const std::uint8_t val_dec = 255;
const std::uint8_t val_bin = 0b11111110;
const std::uint8_t val_oct = 0377;
const std::uint8_t val_hex = 0xff;

int main() {
    assert(val_dec == 255);
    assert(val_bin == 254);
    assert(val_oct == 255);
    assert(val_hex == 255);
    std::cout << "OK!" << std::endl;
    return 0;
}