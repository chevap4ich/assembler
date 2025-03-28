#include <iostream>
#include <cmath>
#include <iomanip>
int main() {
    double x;
    double result1, result2, result3;
    const double const_0 = 0;
    const double const_1 = 1;
    const double const_2 = 2;
    const double const_3 = 3;
    const double const_4 = 4;
    std::cout << "Enter x" << std::endl;
    std::cin >> x;
    __asm {
        movsd xmm0, x 
        ;(x^5 + 2 * (x^2 - 4) + x) / x^3
        ; x^5
        movsd xmm1, xmm0      
        mulsd xmm1, xmm0      
        mulsd xmm1, xmm0      
        mulsd xmm1, xmm0      
        mulsd xmm1, xmm0      
        
        ;2 * (x^2 - 4)
        movsd xmm2, xmm0      
        mulsd xmm2, xmm0        
        subsd xmm2, const_4      
        addsd xmm2, xmm2      

        ; x^5 + 2 * (x^2 - 4) + x
        addsd xmm1, xmm2      
        addsd xmm1, xmm0      

        ; x^3
        movsd xmm2, xmm0      ; xmm2 = x
        mulsd xmm2, xmm0      ; xmm2 = x^2
        mulsd xmm2, xmm0      ; xmm2 = x^3

        ; (x^5 + 2 * (x^2 - 4) + x) / x^3
        ucomisd xmm2, const_0    
        jz no_division        
        divsd xmm1, xmm2      
        jmp done

    no_division:
        movsd xmm1, const_0
    done:
        movsd result1, xmm1
        

        ;(2 * x - 1) * (2 * x + 1) * (x + 3) / (2 * x)
        ;(2 * x - 1)
        movsd xmm1, xmm0
        addsd xmm1, xmm1
        subsd xmm1, const_1
        
        ;(2 * x + 1)
        movsd xmm2, xmm0
        addsd xmm2, xmm2
        addsd xmm2, const_1

        ;(2 * x - 1) * (2 * x + 1)
        mulsd xmm1, xmm2

        ;(x + 3)
        movsd xmm2, xmm0
        addsd xmm2, const_3

        ;(2 * x - 1) * (2 * x + 1) * (x + 3)
        mulsd xmm1, xmm2

        ;(2 * x)
        movsd xmm2, xmm0
        addsd xmm2, xmm2

        ucomisd xmm2, const_0    
        jz no_division1        
        divsd xmm1, xmm2      
        jmp done1

    no_division1:
        movsd xmm1, const_0
    done1:
        movsd result2, xmm1

        ;(4 * x - 1) * (4 * x + 1) / 4

        ;4 * x - 1
        movsd xmm1, xmm0         
        addsd xmm1, xmm1          
        addsd xmm1, xmm1          
        subsd xmm1, const_1       

        ;4 * x + 1
        movsd xmm2, xmm0         
        addsd xmm2, xmm2         
        addsd xmm2, xmm2         
        addsd xmm2, const_1      

        ;(4 * x - 1) * (4 * x + 1)
        mulsd xmm1, xmm2        

        ;(4 * x - 1) * (4 * x + 1) / 4                
        divsd xmm1, const_4         
        movsd result3, xmm1      




    }
    double c_result1, c_result2, c_result3;
    if (x != 0) {
        c_result1 = (pow(x,5) + 2 * (pow(x,2) - 4) + x) / pow(x,3);
    }
    else{
        c_result1 = 0;
    }

    std::cout << "(x^5 + 2 * (x^2 - 4) + x) / x^3" << std::endl;
    std::cout << "Assembler result: " << std::fixed << std::setprecision(10) << result1 << std::endl;
    std::cout << "C++ result: " << c_result1 << std::endl;
    
    if (x != 0) {
        c_result2 = (2 * x - 1) * (2 * x + 1) * (x + 3) / (2 * x);
    }
    else{
        c_result2 = 0;
    }

    std::cout << "(2 * x - 1) * (2 * x + 1) * (x + 3) / (2 * x)" << std::endl;
    std::cout << "Assembler result: " << std::fixed << std::setprecision(10) << result2 << std::endl;
    std::cout << "C++ result: " << c_result2 << std::endl;

    
    c_result3 = (4 * x - 1) * (4 * x + 1) / 4;

    std::cout << "(4 * x - 1) * (4 * x + 1) / 4" << std::endl;
    std::cout << "Assembler result: " << std::fixed << std::setprecision(10) << result3 << std::endl;
    std::cout << "C++ result: " << c_result3 << std::endl;

    
}