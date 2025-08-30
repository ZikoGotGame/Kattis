#include <iostream>

int main()
{
    float b;
    std::cin >> b;
    float squareSide = (b - b / 7.) / 2.;
    std::cout << squareSide * squareSide * 2. + squareSide * squareSide * 6. / 4. * 2.;
    return 0;
}
