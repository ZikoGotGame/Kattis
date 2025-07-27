#include <cstring>
#include <iostream>

int dp[100];

int fib(int n)
{
    if (n <= 2)
        return 1;
    if (dp[n] == -1)
        dp[n] = fib(n - 1) + fib(n - 2);
    return dp[n];
}

bool is_palendrome(std::string input)
{
    return input == std::string(input.rbegin(), input.rend());
}

int main()
{
    std::memset(dp, -1, sizeof(int) * 100);
    while (true)
    {
        std::string input;
        std::cout << "Do you want a fibonacci number?\n";
        std::cin >> input;
        if (input == "yes")
        {
            int n;
            std::cout << "Enter a number: ";
            std::cin >> n;
            std::cout << "the " << n << "th fibonacci number is: " << fib(n) << "\n";
        }
        else if (input == "no")
            break;
        else
            std::cout << "Not a valid input.\n";
    }
    return 0;
}
