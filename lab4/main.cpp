#include <iostream>
#include <cmath>
int main() {
    const double neg1 = -1;
    int k;
    double sum = 0.0;
    const double pi = 3.141592653589793;

    std::cout << "Enter the number of iterations: ";
    std::cin >> k;
    k++;
    __asm {
        finit
        mov eax, 1
        fldz
    loop_:
        test eax, 1
        jz even_
        fld1
        jmp odd_
    even_:
        fld neg1
    odd_:
        push eax
        fild [esp]
        add esp, 4
        fmul st(0), st(0)
        fld1
        fdivrp st(1), st(0)
        fmulp st(1), st(0)
        faddp st(1), st(0)
        inc eax
        cmp eax, k
        jl loop_
    
        fstp sum
    }

    
    std::cout.precision(10);
    std::cout << "Sum: " << sum << '\n';
    std::cout << "Pi^2/12: " << (pi * pi) / 12 << '\n';
    double counted_pi = std::sqrt(sum*12);
    std::cout << "Counted pi: " << counted_pi<< '\n';
    std::cout << "Pi: " << pi<< '\n';
    //точность до 5 знаков - ~1000 итераций
    //точность до 7 знаков - ~10000 итераций
    //точность до 9 знаков - ~100000 итераций  и тд.

    return 0;
}