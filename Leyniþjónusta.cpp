#include <iostream>

int main()
{
    std::string input, output = "";
    while (std::cin >> input)
        output += input;
    std::cout << output;
    return 0;
}
