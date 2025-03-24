#include <iostream>


int main() {
    uint16_t a1 = 0x1234; 
    uint16_t a2 = 0x5678;
    uint16_t a3 = 0x9ABC; 

    uint16_t b1 = 0xFFFF; 
    uint16_t b2 = 0x1111;
    uint16_t b3 = 0x2222; 

    uint16_t c1 = 0;
    uint16_t c2 = 0;
    uint16_t c3 = 0;
    
    __asm {
        mov ax, a1
        mov bx, b1
        add ax, bx
        jnc noCarry1
        add c2, 1
    noCarry1:
        mov c1, ax
        mov ax, a2
        mov bx, b2
        add ax, bx
        jc carry1
        add ax, c2
        jnc noCarry2
        add c3, 1
        jmp noCarry2
    carry1:
        add c3, 1
        add ax, c2

    noCarry2:
        mov c2, ax
        mov ax, a3
        mov bx, b3
        add ax, bx
        add ax, c3
        mov c3, ax

    }
    std::cout << std::hex << c1 << '\n';
    std::cout << std::hex << c2 << '\n';
    std::cout << std::hex << c3 << '\n';
    uint64_t fullResult = (static_cast<uint64_t>(c3) << 32) | (static_cast<uint64_t>(c2) << 16) | c1;
    std::cout << std::dec << fullResult;
}


