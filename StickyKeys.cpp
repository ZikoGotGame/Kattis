#include <iostream>

int main()
{
    std::string S, O = "";
    std::getline(std::cin, S);
    for (int i = 0; i < S.length(); ++i)
    {
        if (i)
        {
            if (S[i - 1] != S[i])
                O += S[i];
        }
        else
        {
            O += S[i];
        }
    }
    std::cout << O;
    return 0;
}
