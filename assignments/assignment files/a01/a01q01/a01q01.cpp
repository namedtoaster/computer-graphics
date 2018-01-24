#include <iostream>

int main()
{
    int value, j;
    std::cin >> value;

    for (int i = 0; i < value; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            int k = j + 1;

            while (k > 0)
            {
                std::cout << '*';
                k--;
            }

            int l = value - (i + 1);
            while (l >= 0)
            {
                std::cout << ' ';
                l--;
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
