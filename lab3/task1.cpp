#include <iostream>

int main(){
    unsigned int a;
    std::cin >> a;
    unsigned int result = 0;
    __asm {
        mov eax, a
        mov ebx, a
        mov ecx, 11
    a12:
        imul eax, ebx
        loop a12
        
        add result, eax
        mov eax, a
        mov ecx, 7
    a8:
        imul eax, ebx
        loop a8

        add result, eax
        add result, ebx

    
        
    }
    
    std::cout << result;
}