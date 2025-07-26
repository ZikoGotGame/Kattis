#include <iostream>

int main()
{
    int N, sum = 0;
    std::cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int l;
        std::cin >> l;
        sum += l - 1;
    }
    std::cout << sum + 1;
    return 0;
}
