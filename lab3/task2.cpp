#include <iostream>
int main() {
    unsigned int arr[48];
    for(int i = 0; i < 48; ++i){
        arr[i] = 0;
    }
    __asm {
        lea eax, arr
        mov [eax], 0
        add eax, 4
        mov [eax], 1
        mov ecx, 46
        mov ebx, 2
    loop1:
        mov eax, arr[4*ebx - 8]
        mov edx, arr[4*ebx - 4]
        add eax, edx
        mov arr[4*ebx], eax
        inc ebx 
        loop loop1 
    }

    for(auto x : arr) {
        std::cout << x << "  ";
    }
}