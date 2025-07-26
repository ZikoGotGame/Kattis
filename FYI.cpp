#include <iostream>

int main()
{
    std::string n;
    std::cin >> n;
    std::cout << (n.find("555") == 0 ? 1 : 0);
    return 0;
}
