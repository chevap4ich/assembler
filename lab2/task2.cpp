#include <iostream>

int main() {
    unsigned int x;
    unsigned int rev_x;
    int result;
    std::cout << "Enter x" << std::endl;
    std::cin >> x;
    const unsigned int const_10 = 10;
    int count = 0;
    int count1 = 0;
    int buffer;
    __asm{
        mov eax, x
        cmp eax, 10
        jl is_palindrome
        xor ebx, ebx


    reverse_loop:
        mov edx, 0             
        div const_10       
        add ebx, edx
        cmp eax, 0
        jz skip_multiplication           
        mov buffer, eax
        mov eax, ebx
        mul const_10
        mov ebx, eax
        mov eax, buffer
    skip_multiplication:    
        cmp eax, 0        
        je done_reverse       
        jmp reverse_loop      

    done_reverse:
        cmp x, ebx
        je is_palindrome
        mov result, 0
        jmp done

    is_palindrome:
        mov result, 1

    done:
    }

    if (result) {
        std::cout << "is palindrome";
    }
    else { 
        std::cout << "isn't palindrome";
    }
}