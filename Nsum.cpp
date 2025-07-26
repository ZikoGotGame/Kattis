#include <iostream>

int main()
{
    int N, sum = 0;
    std::cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int num;
        std::cin >> num;
        sum += num;
    }
    std::cout << sum;
    return 0;
}
