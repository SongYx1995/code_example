#include <iostream>
#include <array>

int main()
{
    std::array<int, 3> a1;
    a1[0] = 1;
    std::cout << a1[0];

    std::array<int, 3> a2 = {1, 2};
    std::cout << a2[1];

}