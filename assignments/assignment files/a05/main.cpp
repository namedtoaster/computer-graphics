#include <iostream>
#include "Mat.h"

int main()
{
    float x[] = {-1, 0, 2, -2, 0, 1, 0, 1, 2, -2, 1, 2, 1, -2, 4, 0};
    Mat< float > m(4, 4, x);
    Mat< float > n;
    try
    {
        n = m.inv();
    }
    catch (Undefined & e)
    {
        std::cout << "Division by zero error" << std::endl;
        return 0;
    
        float d = det(n);
        std::cout << n << std::endl;
        std::cout << (n * m) << std::endl;
    }

    return 0;
}
